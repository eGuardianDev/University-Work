#ifndef BASE_CONNECTIONS_HPP__
#define BASE_CONNECTIONS_HPP__

const std::string SERVER_IP = "127.0.0.1";
const int SERVER_PORT = 8080;

int send_bytes(uint8_t *buff, unsigned int size, int &sock){

    if(size <=4096){

        int bytesSend = send(sock, buff, size,0);
        
        if(bytesSend <0) std::cerr << "Error sending header" << std::endl;
        return bytesSend;
    }
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
    return totalBytes;
}

bool init_socket(int &sock){
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cerr << "Couldn't open socket" << std::endl;
        return false;
    }
    return true;
}
int send_packet(uint8_t *buff,int &sock){
    int total = 0;

    while (total < 3) {
        int n = send(sock, buff + total, 3 - total, 0);
        if (n <= 0) {
            std::cerr << "ERROR | Failed to SEND data with options\n";
            return n; 
        }
        total += n;
    }

    return total; 
}
void clean_socket(int &sock){
    close(sock);
}

int receive_options(int &client, uint8_t *receive_buffer){
    int total = 0;

    while (total < 3) {
        int n = recv(client, receive_buffer + total, 3 - total, 0);
        if (n <= 0) {
            std::cerr << "ERROR | Failed to get data with options\n";
            return n;
        }
        total += n;
    }

    return total; 
}

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
        std::cout << "Data received successfully! Total bytes: " << totalBytes << std::endl;
    }
    return totalBytes;
}

#endif // BASE_CONNECTIONS_HPP__