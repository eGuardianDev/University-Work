
#ifndef CLI_HPP__
#define CLI_HPP__

#include <iostream>
#include <ostream>

#include "utils.hpp"

#include "connection_client.hpp"
#include "ImageProcessing/BMP_File.hpp"
#include <thread>
#include <iomanip>

std::string logo = 
"                                                                                              \n\
                                                                                               \n\
   ██ ██▄  ▄██ ▄████▄  ▄████  ██████   █████▄  ██████ ████▄  ▄████▄ ▄█████ ██████ ▄████▄ █████▄   \n\
   ██ ██ ▀▀ ██ ██▄▄██ ██  ▄▄▄ ██▄▄     ██▄▄██▄ ██▄▄   ██  ██ ██▄▄██ ██       ██   ██  ██ ██▄▄██▄  \n\
   ██ ██    ██ ██  ██  ▀███▀  ██▄▄▄▄   ██   ██ ██▄▄▄▄ ████▀  ██  ██ ▀█████   ██   ▀████▀ ██   ██  \n\
                                                                                              ";

void print_logo(std::ostream &str){
    str << logo << std::endl;
    str << "     ► By Tsvetomir Staykov - 1MI0800469 - 2025 " << std::endl;
}

void print_commands(std::ostream &str){
    std::string data =
"Here are possible commands:\n\
    help - displays this\n\
    exit - stops the program\n\
    load - loads an image to be redacted\n\
    ls - list all files in current directory\n\
    clear - clears terminal\n\
    send - send image and waits for a return\n";
    str << data;
}

void print_manipulation_options(std::ostream &str){
    std::string data =
"Options for image manipulation:\n\
    1    - inverse colours\n\
    2    - gray scale\n\
    4    - black and white\n\
    8    - edge detection\n\
    16   - Gaussian blur\n\
    32   - Gaussian blur (threaded)\n\
    64   - Gabor filter\n\
    128  - Gabor filter (threaded)\n\
    -1   - go back\n";
    str << data;
}

bool send_image(int &fd,int options){
    

    // VALIDATE
    if(fd <2){
        std::cerr << "The given file descriptor is broken" << std::endl;
        return false;
    }

    //ESTABLISH
    sockaddr_in serverAddress{};
    int socket;
    if(!init_socket(socket)) return false;
    if(!set_addr(socket, serverAddress)) {
        clean_socket(socket);
        return false;
    }
    if(!connect_to(socket, serverAddress)) {
        clean_socket(socket);
        return false;
    }

    //READ FILE
    lseek(fd, 0, SEEK_SET);
    uint8_t *buff = new uint8_t[BUFFER_MAX_SIZE];
    int buff_size = read(fd, buff, BUFFER_MAX_SIZE); 

    std::cout << "reading bytes: "<<buff_size << std::endl;
    

    // * SEND OPTIONS
    std::cout << "sending file..." << std::endl;
    uint8_t header[3];
    header[0] = 0x19;
    header[1] = options;
    std::cout <<"send...";
    int header_send_size = send_packet(header,socket); // ! send
    std::cout <<" done!" << std::endl;
    
    if(header_send_size < 3){
        std::cerr << "Error sending data" << std::endl;
        clean_socket(socket);
        return false;
    }

    std::cout <<"receving feedback if settings are coored" << std::endl;

    // * RECEVIE CONFORMATION

    int header_received_size = receive_options(socket, header);
    if(header_received_size < 3){
        std::cerr << "Error | Failed to receive conformation for settings; size not match" << std::endl;
        clean_socket(socket);
        return false;
    }

    int received_status = header[0];

    if(received_status == 0x01){
        std::cerr << "Error | Options denied, because the option is unavailable or non existant" << std::endl;
        clean_socket(socket);
        return false;
    }



    std::this_thread::sleep_for(std::chrono::milliseconds(100));    

    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Sending file..." << std::endl;
    // * SEND FILE
    int size = send_bytes(buff, buff_size, socket); // ! send
    std::cout << "Image is send! Size: " << size << ". Waiting for response." << std::endl;
    

    const unsigned int BUFFER_MAX_SIZE = 25 * 1000 * 1000;
    uint8_t *image_buffer = new uint8_t[BUFFER_MAX_SIZE];
    shutdown(socket, SHUT_WR); 
    
    // * RECEIVE HEADER
    int data =receive_options(socket,header); // ! receive


    if(data <3){
        std::cerr << "Error | Failed to receive predata packet" << std::endl;
        clean_socket(socket);
        return false;
    }

    if(header[0] == 0x01){
        std::cerr << "Error | Something failed in the algorithms" << header[1] << std::endl;
        if(header[1] == 0x01)std::cerr << "\t\t opened file isn't BMP" << std::endl;
        else if(header[1] == 0x02)std::cerr << "\t\t BMP file is v1 which is unsupported" << std::endl;
        else if(header[1] == 0x04)std::cerr << "\t\t file is too small" << std::endl;
        clean_socket(socket);
        return false;
    }
    
    std::cout << "Receving image data: ";
    int data_size = receive_data(socket,image_buffer,BUFFER_MAX_SIZE); // ! receiver
 
    auto end = std::chrono::high_resolution_clock::now();

    double seconds = std::chrono::duration<double>(end - start).count();

    std::cout << std::fixed << std::setprecision(3) <<" TIME | Algorithm applied in " <<  seconds << " seconds\n";

    // * VALIDATE RECEIVED DATA
    if(data_size <0){
        std::cerr << "ERROR: Failed to receive image data" << std::endl;
        delete [] image_buffer;
        close(socket);
        return false;
    }

    std::cout << "Received data: " << data_size << std::endl;
    
    
    int output = open("output.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(output, image_buffer,data_size);
    close(output);
    
    std::cout << "Saved as output.bmp" << std::endl;
        
    // * CLEAN UP
    clean_socket(socket);
    delete [] image_buffer;
    return true;
}

void menu_send(int &fd, const std::string &file_name, std::string option = ""){
    if(option != ""){
        bool status;
        int value = castToNumber(option,status);
        if(status == true){
            send_image(fd, value);
        }else{
            std::cerr << " --> Given option is invalid number" << std::endl;
        }
        return;
    }
    print_manipulation_options(std::cout);
    while(true){
        bool status;
        
        std::string selected;
        std::cout << file_name << ">> ";
        std::getline(std::cin, selected);
        int value = castToNumber(selected,status);
        if(status == true){        
            if(value == -1){
                std::cout << "Exiting send menu..." << std::endl;
                return;
            }
            send_image(fd, value);
            break;
        }
    }
}

#endif //CLI_HPP__
