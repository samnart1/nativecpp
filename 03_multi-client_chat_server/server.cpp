#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

std::vector<int> clients;
std::mutex clients_mutex;

void broadcast_message(const std::string &message, int sender_fd) {
    std::lock_guard<std::mutex> lock(clients_mutex);
    for (int client_fd : clients) {
        if (client_fd != sender_fd) {
            send(client_fd, message.c_str(), message.length(), 0);
        }
    }
}

void handle_client(int client_fd, struct sockaddr_in client_addr) {
    char buffer[BUFFER_SIZE];
    std::string client_ip = inet_ntoa(client_addr.sin_addr);
    int client_port = ntohs(client_addr.sin_port);

    std::cout << "New client connected: " << client_ip << ":" << client_port << " (fd: " << client_fd << ")\n";

    //notify others about new client
    std::string join_msg = "[Server] Client " + std::to_string(client_fd) + " joined the chat\n";
    broadcast_message(join_msg, client_fd);

    //send welcome message to new client
    std::string welcome = "[Server] Welcome! You are client " + std::to_string(client_fd) + "\n";
    send(client_fd, welcome.c_str(), welcome.length(), 0);

    
}