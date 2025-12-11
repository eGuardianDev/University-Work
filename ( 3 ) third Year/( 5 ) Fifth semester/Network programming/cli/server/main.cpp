
#include "connection_server.hpp"

int main(){

    int sock;
    
    if(!initSocket(sock)){return 1;}
    sockaddr_in addr{};
    if(!setAddr(addr)){cleanSock(sock); return 1;};
    if(!bindSocket(sock,addr)){cleanSock(sock); return 1;}
    if(!listenSocket(sock)){        cleanSock(sock); return 1;};
    
    std::cout << "Started server" << std::endl;
    while(true){
        std::cout << "Waiting for connection.." << std::endl;
        accept_client(sock);
    }
    return 0;
}