#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t client_len = sizeof(client_addr);

    //SOCK_DGRAM: socket datagram: for udp socket creation.
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // configure server
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    //bind socket to port
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        return -1;
    }

    std::cout << "UDP Echo server listening on port " << PORT << "...\n";
    std::cout << "Waiting for messages...\n\n";

    //main echo loop
    while(true) {
        memset(buffer, 0, BUFFER_SIZE);

        //receive message from client
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &client_len);

        if (n < 0) {
            perror("Receive failed");
            continue;
        }

        buffer[n] = '\0';

        //display received message
        std::cout << "Received from " << inet_ntoa(client_addr.sin_addr) << ":" << ntohs(client_addr.sin_port) << " - " << buffer << std::endl;

        //echo message back to client
        sendto(sockfd, buffer, n, 0, (const struct sockaddr *)&client_addr, client_len);

        std::cout << "Echoed back: " << buffer << "\n\n";

        // optional: exit if "exit" received
        if (strcmp(buffer, "exit") == 0) {
            std::cout << "Exit command received. Shutting down...\n";
            break;
        }
    }

    close(sockfd);
    return 0;
}