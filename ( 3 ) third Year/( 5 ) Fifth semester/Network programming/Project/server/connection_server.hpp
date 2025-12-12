#ifndef CONNECT_SERVER_HPP__
#define CONNECT_SERVER_HPP__



#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <algorithm>
#include <thread>
#include "../connection_client.hpp"
#include "../ImageProcessing/BMP_File.hpp"
#include "../ImageProcessing/BMP_Manipulation.hpp"
#include "../ImageProcessing/Algorithms.hpp"


bool setAddr(sockaddr_in &serverAddress, const int &port =8080){
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    return true;
}
bool bindSocket(int &sock, sockaddr_in &serverAddress){
    if (bind(sock, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Couldn't bind a socket" << std::endl;
        return false;
    }
    return true;
}
bool listenSocket(int &sock){
    if (listen(sock, 5) < 0) {
        std::cerr << "Cannot listen to server socket" << std::endl;
        return false;
    }
    return true;
}


int apply_Algorithm(uint8_t * bmp_data, uint8_t *dst, uint size, int algorithms){

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

    std::cout << "\t image size: " << header.image_size << std::endl;

    bool flag = algorithms & 0x01;
    if((algorithms & 0x01)){
        //inverse
    }
    algorithms = algorithms >> 1;
    if(algorithms & 0x01){
        Algo_Gray_Scale(bmp_data +header.data_offset ,dst+header.data_offset, header.image_size);
        // gray
    }
    algorithms = algorithms >> 1;
    if(algorithms & 0x01){
        //black and white
    }
    algorithms = algorithms >> 1;
    if(algorithms & 0x01){
        //edge detection
    }
    algorithms = algorithms >> 1;
    if(algorithms & 0x01){
        //gaussian blur
    }
    algorithms = algorithms >> 1;
    if(algorithms & 0x01){
        //gaussian blur (threaded)
    }

    return 0;
}

void client_handle(int client, int fd){
       

    // * SETUP DATA
    const unsigned int BUFFER_MAX_SIZE = 25 * 1000 * 1000;
    uint8_t *image_buffer = new uint8_t[BUFFER_MAX_SIZE];


    // * RECEIVE OPTIONS
    uint8_t header[3]; // request, subtype, other
    // int bytesReceived = recv(client, header, 3, 0);
    int bytesReceived = receive_options(client,header);

    if (bytesReceived < 3) {
        std::cerr << "Error writting to file" << std::endl;
        cleanSock(client);
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
    if(header[1] > 0 && header[1] <64 ){
        std::cout << " #" << (int)header[1] << std::endl;
        header[0] = 0x00;
        int size = send_packet(header,client);
        if(size <3){
            std::cerr << "ERROR | Failed to send confirmation header" << std::endl;
            cleanSock(client);
            return;
        }
    }else{
        std::cout << ", but edit type is not available " << (int)(header[1]) << std::endl;
        header[0] = 0x01;
        int size = sendBytes(header,3,client);
        if(size <3){
            std::cerr << "ERROR | Failed to send confirmation header" << std::endl;
        }
        cleanSock(client);
        return;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));    
    // // * RECEIVE FILE
    std::cout << "Receving data..." << std::endl;
    int data_size = receive_data(client,image_buffer,BUFFER_MAX_SIZE); // ! here
    
    if(data_size <=0){
        std::cerr << "Failed to receive data" << std::endl;
        delete [] image_buffer;
        close(client);
        close(fd);
        return;
    }
        
    // // // * PROCESS IMAGE
        std::cout << "Image Processing... ";

        uint8_t *modified_image = new uint8_t[BUFFER_MAX_SIZE];
        int status = apply_Algorithm(image_buffer, modified_image, data_size, algo);
        std::cout << "Done!" << std::endl;

        
        if(status != 0){
            std::cerr <<"Algorithm is bad" << std::endl;
            header[0] = 0x01;   // fail
            header[1] = status; // error code
            int size = send_packet(header,client);
            close(client);
            close(fd);
            delete [] image_buffer;
            return;
        }
        std::cout <<"Algorithm ended good" << std::endl;
 
        header[0] = 0x00;
        int size = send_packet(header,client);

        std::cout << "Returning file:" << std::endl;
        std::cout << "size is "<< data_size << std::endl;
        sendBytes(modified_image, data_size,client);        //! here
        std::cout << " -- end of return -- " << std::endl;

    // * CLEAN UP
        delete [] image_buffer;
        close(client);
        close(fd);
}

bool accept_client(int &sock){
    int clientSocket = accept(sock, nullptr, nullptr);
    if (clientSocket < 0) {
        std::cerr << "Error in accepting connections" << std::endl;
        return false;
    }

   

    std::string name = "output.bmp";
    int fd = open(name.c_str(), O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (fd == -1) {
        std::cerr << "Couldn't open output file" << std::endl;
        cleanSock(clientSocket);
        return false;
    }
    std::thread(client_handle,clientSocket, fd).detach();

    return true;
}

#endif //CONNECT_SERVER_HPP__