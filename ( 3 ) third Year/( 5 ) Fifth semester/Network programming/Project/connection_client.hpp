#ifndef CONNECTION_CLIENT__
#define CONNECTION_CLIENT__

#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>      

#include "Base_connections.hpp"


bool set_addr(int &sock, sockaddr_in &serverAddress,  const std::string &addr = SERVER_IP, const int &port =SERVER_PORT){
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);

    if (inet_pton(AF_INET, addr.c_str(), &serverAddress.sin_addr) <= 0) {
        std::cerr << "Couldn't get address" << std::endl;
        return false;
    }
    return true;
}

bool connect_to(int &sock, sockaddr_in &addr){
    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        std::cerr << "Couldn't connect to address" << std::endl;
        return false;
    }
    return true;
}
#endif //CONNECTION_CLIENT__