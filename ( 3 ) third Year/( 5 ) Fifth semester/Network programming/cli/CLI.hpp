
#ifndef CLI_HPP__
#define CLI_HPP__

#include <iostream>
#include <ostream>

#include "utils.hpp"

#include "connection_client.hpp"

std::string logo = 
"                                                                                              \n\
                                                                                               \n\
   ██ ██▄  ▄██ ▄████▄  ▄████  ██████   █████▄  ██████ ████▄  ▄████▄ ▄█████ ██████ ▄████▄ █████▄   \n\
   ██ ██ ▀▀ ██ ██▄▄██ ██  ▄▄▄ ██▄▄     ██▄▄██▄ ██▄▄   ██  ██ ██▄▄██ ██       ██   ██  ██ ██▄▄██▄  \n\
   ██ ██    ██ ██  ██  ▀███▀  ██▄▄▄▄   ██   ██ ██▄▄▄▄ ████▀  ██  ██ ▀█████   ██   ▀████▀ ██   ██  \n\
                                                                                              ";

void printLogo(std::ostream &str){
    str << logo << std::endl;
    str << "     ► By Tsvetomir Staykov - 1MI0800469 - 2025 " << std::endl;
}

void printCommands(std::ostream &str){
    std::string data =
"Here are possible commands:\n\
    help - displays this\n\
    exit - stops the program\n\
    load - loads an image to be redacted\n\
    check - check connection with server\n\
    ls - list all files in current directory\n\
    clear - clears terminal\n\
    send - send image and waits for a return\n";
    str << data;
}

void print_manipulation_options(std::ostream &str){
    std::string data =
"Options for image manipulation:\n\
    0    - inverse colours\n\
    1    - gray scale\n\
    2    - black and white\n\
    4    - edge detection\n\
    8    - gaussian blur\n\
    16   - gaussian blur (threaded)\n\
    -1   - go back\n";
    str << data;
}

bool send_image(int &fd,int options){
    
    if(fd <2){
        std::cerr << "The given file descriptor is broken" << std::endl;
        return false;
    }

    sockaddr_in serverAddress{};
    int socket;
    if(!initSocket(socket)) return false;
    if(!setAddr(socket, serverAddress)) {
        cleanSock(socket);
        return false;
    }
    if(!connect(socket, serverAddress)) {
        cleanSock(socket);
        return false;
    }
    lseek(fd, 0, SEEK_SET);
    const int MAX_BUFF_SIZE = 25 * 1000 * 1000;
    uint8_t *buff = new uint8_t[MAX_BUFF_SIZE];
    int buff_size = read(fd, buff, MAX_BUFF_SIZE); 

    std::cout << "reading bytes: "<<buff_size << std::endl;
    std::cout << "sending file..." << std::endl;

    uint8_t header[3];
    header[0] = 0x19;
    header[1] = options;
    int header_ping= sendBytes(header, 3, socket);
    
    if(header_ping <3){
        std::cerr << "Error sending data" << std::endl;
        cleanSock(socket);
        return false;
    }

    int size = sendBytes(buff, buff_size, socket);
    std::cout << "Image is send! Size: " << size << ". Waiting for response." << std::endl;
    

    const unsigned int BUFFER_MAX_SIZE = 25 * 1000 * 1000;
    uint8_t *image_buffer = new uint8_t[BUFFER_MAX_SIZE];


    int data_size = receive_data(socket,image_buffer,BUFFER_MAX_SIZE);
    if(data_size <=0){
        std::cerr << "Failed to receive data" << std::endl;
        delete [] image_buffer;
        close(socket);
        return false;
    }
    std::cout << "Returned image! Saved as output.bmp" << std::endl;
    std::cout << "Received data: " << data_size << std::endl;
    
    
    int output = open("output.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(output, image_buffer,data_size);

    close(output);
    cleanSock(socket);
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
