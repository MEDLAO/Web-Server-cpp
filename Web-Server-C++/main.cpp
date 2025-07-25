//
//  main.cpp
//  Web-Server-C++
//
//  Created by MEDLAO on 06/07/2025.
//

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


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
    
    // Step 4: Bind the socket to the IP/port we set in server_addr
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Binding failed.\n";
        return 1;
    }
    
    // Step 5: Listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        std::cerr << "Listening failed. \n";
        return 1;
    }
    
    std::cout << "Server is listening on port 8080... \n";
    
    // Step 6: Accepting incoming requests
    sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_socket = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
    
    char buffer[1024] = {0};
    
    // Step 7: Read data sent by the client
    int bytes_read = read(client_socket, buffer, sizeof(buffer));
    if (bytes_read < 0) {
        std::cerr << "Failed to read from client.\n";  // Print an error message if read() failed
    } else {
        std::cout << "Received from client: " << buffer << "\n";  // Otherwise, print the received data
    }
    
    
    // Step 8: Send a simple HTTP response
    const char* http_response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello from C++ server!";
    send(client_socket, http_response, strlen(http_response), 0);
    
    // Close the client socket after responding
    close(client_socket);
    
    // Close the server socket before exiting
    close(server_fd);
    
    // Keep the server running so we can test it
    std::cout << "Press Enter to stop the server... \n";
    std::cin.get(); // Wait forn the user to press Enter
    
    return 0;
}
