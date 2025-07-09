//
//  main.cpp
//  Web-Server-C++
//
//  Created by MEDLAO on 06/07/2025.
//

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>


int main(int argc, const char * argv[]) {
    // Step 1: Create a socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    // Step 2: Check if the socket was created successfully
    if (server_fd == -1) {
        std::cerr << "Failed to create socket. \n";
        return 1;
    }
    
    std::cout << "Socket created successfully. File descriptor = " << server_fd << "\n";
    
    // Step 3: Create address structure
    sockaddr_in server_addr{};  // zero-initializes the structure
    
    // Set the address family to IPv4
    server_addr.sin_family = AF_INET;
    
    // Set the port number to 8080 and convert it to network byte order
    server_addr.sin_port = htons(8080);
    
    // Accept connections on any IP address of this machine (0.0.0.0)
    server_addr.sin_addr.s_addr = INADDR_ANY;
    
    return 0;
}
