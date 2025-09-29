#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed.");
        return -1;
    }

    // configure server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    //convert ipv4 address from text to binary
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address");
        close(sock);
        return -1;
    } 

    // coonnect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return -1;
    }

    std::cout << "Connected to server!\n";
    std::cout << "Type 'exit' to quit\n\n";

    //communication loop
    while (true) {
        //send message
        std::cout << "Client: ";
        std::string message;
        std::getline(std::cin, message);
        send(sock, message.c_str(), message.length(), 0);

        if (message == "exit") {
            std::cout << "Closing connection...\n";
            break;
        }

        //receive response
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_read = read(sock, buffer, BUFFER_SIZE);
        if (bytes_read <= 0) {
            std::cout << "Server disconnected\n";
            break;
        }

        std::cout << "Server: " << buffer << std::endl << std::endl;

        if (strcmp(buffer, "exit") == 0) {
            std::cout << "Server closed connection\n";
            break;
        }
    }

    close(sock);

    return 0;
}