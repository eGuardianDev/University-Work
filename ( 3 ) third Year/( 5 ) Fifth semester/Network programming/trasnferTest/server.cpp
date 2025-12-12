// server.cpp
#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <thread>
using namespace std;

void client_handle(int client, int file);

int main() {
    // Create socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("socket");
        return 1;
    }

    // Allow quick restart of the server
    int opt = 1;
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        std::cerr << "Fail configuring socket" << std::endl;
        close(serverSocket);
        return 1;
    }

    // Open output file

    // Specify address
    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Couldn't bind a socket" << std::endl;
        close(serverSocket);
        return 1;
    }

    // Listen
    if (listen(serverSocket, 5) < 0) {
        std::cerr << "Cannot listen to server socket" << std::endl;
        close(serverSocket);
        return 1;
    }

    cout << "Server listening on port 8080..." << endl;

    int i =0;
    while(true){
   
        std::cout << "Waiting for connection.." << std::endl;
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket < 0) {
            std::cerr << "Error in accepting connections" << std::endl;
            close(serverSocket);
            return 1;
        }
        std::string name = "output" + to_string(i)+ ".bmp";
        int fd = open(name.c_str(), O_CREAT | O_WRONLY | O_TRUNC, 0664);
        if (fd == -1) {
            std::cerr << "Couldn't open output file" << std::endl;
            close(serverSocket);
            return 1;
        }

  /*
    uint32_t packet[3];
    packet[0] = 1;
    packet[1] = 2;
    packet[2] = 3;

    ssize_t bytesSend = recv(clientSocket, packet, sizeof(packet),0);

    if(bytesSend <0){
        std::cerr << "Error sending header" << std::endl;
        close(fd);
        close(clientSocket);
        return 1;
    }

    std::cout << "Header:";
    std::cout << packet[0] << " " << packet[1] << " " << packet[2] << std::endl;

    std::cout << "send bytes: "<<bytesSend << std::endl;
*/
    // Receive file in chunks

        std::thread(client_handle,clientSocket, fd).detach();
        ++i;
    }

    close(serverSocket);

    return 0;
}


void client_handle(int client, int fd){
        const size_t BUF_SIZE = 4096;
        uint8_t buffer[BUF_SIZE];
        ssize_t bytesReceived;
        size_t totalBytes = 0;

        while ((bytesReceived = recv(client, buffer, BUF_SIZE, 0)) > 0) {
            if (write(fd, buffer, bytesReceived) != bytesReceived) {
                std::cerr << "Error writting to file" << std::endl;
                close(client);
                close(fd);
                close(client);
                return;
            }
            totalBytes += static_cast<size_t>(bytesReceived);
        }

        if (bytesReceived < 0) {
            std::cerr << "Error in receiving data" << std::endl;
            
        } else {
            cout << "File received successfully! Total bytes: " << totalBytes << endl;
        }
        close(client);
        close(fd);
}
