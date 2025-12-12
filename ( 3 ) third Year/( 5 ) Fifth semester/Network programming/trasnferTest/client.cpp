// client.cpp
#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>  // for inet_pton
#include <chrono>
#include <thread>
#include <random>

using namespace std;

int main() {
    
    // Open input file
    int fd = open("input.bmp", O_RDONLY);
    if (fd == -1) {
        std::cerr << "Couldn't open file" << std::endl;
        return 1;
    }

    // Create socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Couldn't open socket" << std::endl;
        close(fd);
        return 1;
    }

    // Server address (localhost:8080)
    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);

    if (inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr) <= 0) {
        std::cerr << "Couldn't get address" << std::endl;
        close(fd);
        close(clientSocket);
        return 1;
    }

    // Connect to server
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Couldn't connect to address" << std::endl;
        close(fd);
        close(clientSocket);
        return 1;
    }

    uint32_t packet[3];
    packet[0] = 1;
    packet[1] = 2;
    packet[2] = 3;

    ssize_t bytesSend = send(clientSocket, packet, sizeof(packet),0);

    if(bytesSend <0){
        std::cerr << "Error sending header" << std::endl;
        close(fd);
        close(clientSocket);
        return 1;
    }
    std::cout << "send bytes: "<<bytesSend << std::endl;

    // Send file in chunks
    const size_t BUF_SIZE = 4096;
    uint8_t buffer[BUF_SIZE];
    ssize_t bytesRead;
    size_t totalBytes = 0;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(3, 7);

    int seconds = dist(gen);
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    while ((bytesRead = read(fd, buffer, BUF_SIZE)) > 0) {
        ssize_t bytesSentTotal = 0;
        bool flag = false;
        while (bytesSentTotal < bytesRead) {
          
            ssize_t bytesSent = send(clientSocket, buffer + bytesSentTotal,
                                     bytesRead - bytesSentTotal, 0);
            if (bytesSent < 0) {
                std::cerr << "Sending error" << std::endl;
                close(fd);
                close(clientSocket);
                return 1;
            }
            bytesSentTotal += bytesSent;
        }
        totalBytes += static_cast<size_t>(bytesRead);
    }

    if (bytesRead < 0) {
        std::cerr << "Error in readings from file." << std::endl;
    } else {
        cout << "File sent successfully! Total bytes: " << totalBytes << endl;
    }

    close(fd);
    close(clientSocket);

    return 0;
}
