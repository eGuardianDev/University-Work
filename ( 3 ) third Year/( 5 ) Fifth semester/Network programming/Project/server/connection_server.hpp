#ifndef CONNECT_SERVER_HPP__
#define CONNECT_SERVER_HPP__

#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <algorithm>
#include <thread>
#include <cstring>
#include "../ImageProcessing/BMP_File.hpp"
#include "../ImageProcessing/BMP_Manipulation.hpp"
#include "../ImageProcessing/Algorithms.hpp"
#include "../Base_connections.hpp"
#include <mutex>




bool set_addr(sockaddr_in &serverAddress, const int &port =SERVER_PORT){
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    return true;
}
bool bind_socket(int &sock, sockaddr_in &serverAddress){
    if (bind(sock, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Couldn't bind a socket" << std::endl;
        return false;
    }
    return true;
}
bool listen_socket(int &sock){
    if (listen(sock, 5) < 0) {
        std::cerr << "Cannot listen to server socket" << std::endl;
        return false;
    }
    return true;
}


int apply_algorithm(uint8_t * bmp_data, uint8_t *dst, uint size, int algorithms){

    if(size < 138){
        std::cerr << "Algorithm failed, due to small size of input!" << std::endl;
        return 5;
    }
    unsigned char buff_header[138];
    memcpy(buff_header, bmp_data, 138);
    memcpy(dst, bmp_data, 138);

    bmp_header header = load_header(buff_header);  

    if(bmp_data[0] != 'B' || bmp_data[1] != 'M'){
        std::cerr << "Opened file isn't a BMP format." << std::endl;
        return 1;
    }
    uint8_t header_size = *(uint8_t*)&bmp_data[14];
    if(header_size == 12){
        std::cout << "Header is v1 and is unsupported" << std::endl;
        return 2;
    }
    header_print_basic(header);

    uint8_t* work = new uint8_t[size];
    memcpy(work, bmp_data, size);

    uint8_t* in  = work;
    uint8_t* out = dst;
    std::cout << "width*3 = " << header.width*3 << std::endl;
    std::cout << "image_size / height = " << header.image_size / header.height << std::endl;

    std::cout << "\t image size: " << header.image_size << std::endl;

    bool flag = algorithms & 0x01;
    if((algorithms & 0x01)){
        Algo_Invert_Colours(in+header.data_offset,out+header.data_offset, header.image_size);
        std::cout << "Applied inverse colour" << std::endl;
        //inverse
        std::swap(in, out);
    }
    algorithms = algorithms >> 1;
    if(algorithms & 0x01){
        Algo_Gray_Scale(in +header.data_offset ,out+header.data_offset, header.image_size);
        std::cout << "Applied gray scale" << std::endl;
        // gray
        std::swap(in, out);
    }
    algorithms = algorithms >> 1;
    if(algorithms & 0x01){
        //black and white
        Algo_Black_White(in+header.data_offset, out+header.data_offset, header.image_size);
        std::swap(in, out);

    }
    algorithms = algorithms >> 1;
    if(algorithms & 0x01){
        //edge detection
        Algo_Sobel_Edge(in + header.data_offset, out+header.data_offset, header.width, header.height);
        std::cout << "Applied edge detection" << std::endl;
        std::swap(in, out);
    }
    algorithms = algorithms >> 1;
    if(algorithms & 0x01){
        //gaussian blur
        // memcpy(out, in, size);
        Algo_Gaussian_Blur(in + header.data_offset, out+header.data_offset, header.width, header.height,1);
        std::swap(in, out);
    }
    algorithms = algorithms >> 1;
    if(algorithms & 0x01){
        Algo_Gaussian_Blur(in + header.data_offset, out+header.data_offset, header.width, header.height);
        //gaussian blur (threaded)
        std::swap(in, out);
    }
    algorithms = algorithms >> 1;
    if(algorithms & 0x01){
        float theta = 90 *M_PI /180;
        Algo_Gabor_Filter(
            in  + header.data_offset,
            out + header.data_offset,
            header.width,
            header.height,
            21,          // ksize (odd!)
            4.0f,        // sigma
            theta,       // orientation
            10.0f,       // lambda
            0.5f,        // gamma
            0.0f,         // psi
            1
        );

        //gaussian blur (threaded)
        std::swap(in, out);
    }
     algorithms = algorithms >> 1;
    if(algorithms & 0x01){
        float theta = 90 *M_PI /180;
        Algo_Gabor_Filter(
            in  + header.data_offset,
            out + header.data_offset,
            header.width,
            header.height,
            21,          // ksize (odd!)
            4.0f,        // sigma
            theta,       // orientation
            10.0f,       // lambda
            0.5f,        // gamma
            0.0f,         // psi
            0
        );

        //gaussian blur (threaded)
        std::swap(in, out);
    }
    
    if (in != dst) {
        memcpy(dst + header.data_offset,
               in + header.data_offset,
               header.image_size);
    }
    delete [] work;

    return 0;
}

void client_handle(int client){
       

    // * SETUP DATA
    uint8_t *image_buffer = new uint8_t[BUFFER_MAX_SIZE];


    // * RECEIVE OPTIONS
    uint8_t header[3]; // request, subtype, other
    // int bytesReceived = recv(client, header, 3, 0);
    int bytesReceived = receive_options(client,header);

    if (bytesReceived < 3) {
        std::cerr << "Error writting to file" << std::endl;
        clean_socket(client);
        return;
    }
    int request = header[0];
    int algo = header[1];
    int freeSlot = header[2];

    if(header[0] != 0x19){
        std::cerr << "Invalid header data request on [0] -> "<< header[0] << std::endl;
        return;
    }

    std::cout << "Requiested image editing";
    if(header[1] > 0 && header[1] <=255 ){
        std::cout << " #" << (int)header[1] << std::endl;
        header[0] = 0x00;
        int size = send_packet(header,client);
        if(size <3){
            std::cerr << "ERROR | Failed to send confirmation header" << std::endl;
            clean_socket(client);
            return;
        }
    }else{
        std::cout << ", but edit type is not available " << (int)(header[1]) << std::endl;
        header[0] = 0x01;
        int size = send_bytes(header,3,client);
        if(size <3){
            std::cerr << "ERROR | Failed to send confirmation header" << std::endl;
        }
        clean_socket(client);
        return;
    }

    // * RECEIVE FILE
    std::cout << "Receving data..." << std::endl;
    int data_size = receive_data(client,image_buffer,BUFFER_MAX_SIZE); // ! here
    
    if(data_size <=0){
        std::cerr << "Failed to receive data" << std::endl;
        delete [] image_buffer;
        close(client);
        // close(fd);
        return;
    }
        
    //* PROCESS IMAGE
        std::cout << "Image Processing... ";

        uint8_t *modified_image = new uint8_t[BUFFER_MAX_SIZE];
        int status = apply_algorithm(image_buffer, modified_image, data_size, algo);
        std::cout << "Done!" << std::endl;

        
        if(status != 0){
            std::cerr <<"Algorithm endded badly. Sending report" << std::endl;
            header[0] = 0x01;   // fail
            header[1] = status; // error code
            int size = send_packet(header,client);
            close(client);
            // close(fd);
            delete [] image_buffer;
            return;
        }
        std::cout <<"Algorithm ended good. Sending report" << std::endl;
 
        header[0] = 0x00;
        int size = send_packet(header,client);

        std::cout << "Returning file:" << std::endl;
        std::cout << "size is "<< data_size << std::endl;
        send_bytes(modified_image, data_size,client);        //! here
        std::cout << " -- end of return -- " << std::endl;

        // * CLEAN UP
        delete [] image_buffer;
        close(client);
}

bool accept_client(int &sock){
    int clientSocket = accept(sock, nullptr, nullptr);
    if (clientSocket < 0) {
        std::cerr << "Error in accepting connections" << std::endl;
        return false;
    }
    std::thread(client_handle,clientSocket).detach();

    return true;
}

#endif //CONNECT_SERVER_HPP__