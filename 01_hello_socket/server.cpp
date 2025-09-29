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
    int server_fd, client_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket failed");
        return -1;
    }

    // set socket options to reuse address
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        close(server_fd);
        return -1;
    }

    //configure address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    //bind socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        return -1;
    }

    //listen tofor connections
    if(listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        return -1;
    }

    std::cout << "Server listening on port " << PORT << "...\n";

    //accept connection
    client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    if (client_fd < 0) {
        perror("Accept failed");
        close(server_fd);
        return -1;
    }

    std::cout << "Client connected!\n";

    //communication loop
    while (true) {
        memset(buffer, 0, BUFFER_SIZE);
        
        // receive message
        int bytes_read = read(client_fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0) {
            std::cout << "Client disconnected\n";
            break;
        }

        std::cout << "Client: " << buffer << std::endl;

        //check for exit command
        if (strcmp(buffer, "exit") == 0) {
            std::cout << "Closing connection...\n";
            break;
        }

        //send response
        std::cout << "Server: ";
        std::string response;
        std::getline(std::cin, response);
        send(client_fd, response.c_str(), response.length(), 0);

        if (response == "exit") {
            std::cout << "Closing connection...\n";
            break;
        }
    }

    //cleanup
    close(client_fd);
    close(server_fd);

    return 0;
}