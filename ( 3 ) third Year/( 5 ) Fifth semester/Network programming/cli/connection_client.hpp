#ifndef CONNECTION_CLIENT__
#define CONNECTION_CLIENT__

#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>      


int receive_data(int &client, uint8_t *receive_buffer, const int BUFFER_MAX_SIZE){
    const unsigned int BUF_SIZE = 4096;
    uint8_t buffer[BUF_SIZE];
    unsigned int bytesReceived;
    unsigned int totalBytes = 0;

    while ((bytesReceived = recv(client, buffer, BUF_SIZE, 0)) > 0) {
        
        if (totalBytes + bytesReceived > BUFFER_MAX_SIZE) {
            std::cerr << "Image buffer overflow — incoming data too large\n";
            close(client);
            return -1;
        }
        memcpy(receive_buffer + totalBytes, buffer, bytesReceived);
        
        totalBytes += bytesReceived;
    }

    if (bytesReceived < 0) {
        std::cerr << "Error in receiving data" << std::endl;
    } else {
        std::cout << "File received successfully! Total bytes: " << totalBytes << std::endl;
    }
    return totalBytes;
}

bool initSocket(int &sock){
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cerr << "Couldn't open socket" << std::endl;
        return false;
    }
    return true;
}

bool setAddr(int &sock, sockaddr_in &serverAddress,  const std::string &addr = "127.0.0.1", const int &port =8080){
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);

    if (inet_pton(AF_INET, addr.c_str(), &serverAddress.sin_addr) <= 0) {
        std::cerr << "Couldn't get address" << std::endl;
        return false;
    }
    return true;
}
bool connect(int &sock, sockaddr_in &addr){
    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        std::cerr << "Couldn't connect to address" << std::endl;
        return false;
    }
    return true;
}

int sendBytes(uint8_t *buff, unsigned int size, int &sock){

    if(size <=4096){

        int bytesSend = send(sock, buff, size,0);
        
        if(bytesSend <0) std::cerr << "Error sending header" << std::endl;
        else std::cout << "send bytes: "<<bytesSend << std::endl;
        return bytesSend;
    }
        
    // Send file in chunks
    const int BUF_SIZE = 4096;
    unsigned int totalBytes = 0;

    while (totalBytes < size) {
        unsigned int chunkBytesSent = 0;

        int toSend = std::min((unsigned int)BUF_SIZE, size-totalBytes);
                
        while (chunkBytesSent < toSend) {
            int bytesSent = send(sock, buff + totalBytes + chunkBytesSent ,
                                       toSend - chunkBytesSent,0);
            if (bytesSent < 0) {
                std::cerr << "Sending error" << std::endl;
                return bytesSent;
            }
            chunkBytesSent += bytesSent;
        }
        totalBytes += chunkBytesSent;
    }

    if (totalBytes != size) {
        std::cerr << "Error sending data." << std::endl;
    } else {
        std::cout << "File sent successfully! Total bytes: " << totalBytes << std::endl;
    }
    shutdown(sock, SHUT_WR);
    return totalBytes;
}

void cleanSock(int &sock){
    close(sock);
}

#endif //CONNECTION_CLIENT__