
#include "connection_server.hpp"

int main(){

    int sock;
    
    if(!init_socket(sock)){return 1;}
    sockaddr_in addr{};
    if(!set_addr(addr)){clean_socket(sock); return 1;};
    if(!bind_socket(sock,addr)){clean_socket(sock); return 1;}
    if(!listen_socket(sock)){clean_socket(sock); return 1;};
    
    std::cout << "Started server" << std::endl;
    while(true){
        std::cout << "Waiting for connection.." << std::endl;
        accept_client(sock);
    }
    return 0;
}