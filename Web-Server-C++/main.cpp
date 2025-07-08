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
    
    return 0;
}
