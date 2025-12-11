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


void client_handle(int client, int fd, int algo){
       
        const unsigned int BUFFER_MAX_SIZE = 25 * 1000 * 1000;
        uint8_t *image_buffer = new uint8_t[BUFFER_MAX_SIZE];

        std::cout << "Receving data..." << std::endl;
        int data_size = receive_data(client,image_buffer,BUFFER_MAX_SIZE);
        if(data_size <=0){
            std::cerr << "Failed to receive data" << std::endl;
            delete [] image_buffer;
            close(client);
            close(fd);
            return;
        }
        
        std::cout << "Writing file..." << std::endl;
        if (write(fd, image_buffer, data_size) != data_size) {
            std::cerr << "Error writting to file" << std::endl;
            close(client);
            close(fd);
            delete [] image_buffer;

            return;
        }

        std::cout << "Returning file:" << std::endl;

        std::cout << "size is "<< data_size << std::endl;
        sendBytes(image_buffer, data_size,client);
        std::cout << "end of return" << std::endl;

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

    uint8_t header[3]; // request, subtype, other
    int bytesReceived = recv(clientSocket, header, 3, 0);

    if (bytesReceived < 3) {
        std::cerr << "Error writting to file" << std::endl;
        cleanSock(clientSocket);
        return false;
    }
    int algo = header[1];

    if(header[0] == 0x19){
        std::cout << "Requiested image editing";
        if(header[1] >= 0 && header[1] <64 ){
            std::cout << " #" << (int)header[1] << std::endl;
        }else{
            std::cout << ", but edit type is not available " << (int)(header[1]) << std::endl;
            cleanSock(clientSocket);
            return false;
        }
    }else{
        std::cerr << "invalid header data "<< header[0] << std::endl;
        return false;
    }

    std::string name = "output.bmp";
    int fd = open(name.c_str(), O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (fd == -1) {
        std::cerr << "Couldn't open output file" << std::endl;
        cleanSock(clientSocket);
        return false;
    }
    std::thread(client_handle,clientSocket, fd, algo).detach();

    return true;
}

#endif //CONNECT_SERVER_HPP__