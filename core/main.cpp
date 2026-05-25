#include <cstdlib>
#include <cstring>
#include <ostream>
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>

int main()
{
  std::cout << "Initializing TCP server\n"; 
  constexpr int PORT = 8080;
  constexpr int BACKLOG = 5;
  constexpr int BUFFER_SIZE = 1024;
  
  // First socket implementation will be manual and minimalistic for speed and educational purpose
  // Second version will use the modern posix API with getaddrinfo() etc... 

  // Be sure to understand and write down what a "file descriptor" is
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);  
  if (socket_fd == -1)
  {
    // Define error handling stategy, errors vs exceptions
    // Program should exit on failure here
  }
  std::cout << "Main listening socket created, file descriptor number : " << socket_fd << "\n";

  sockaddr_in server_socket_addr {};
  server_socket_addr.sin_family = AF_INET;
  server_socket_addr.sin_port = htons(PORT);
  server_socket_addr.sin_addr.s_addr = INADDR_ANY;

  int bound = bind(socket_fd, (struct sockaddr*)&server_socket_addr, sizeof(server_socket_addr));
  if (bound != 0) 
  {
    // Handle error, shutdown program correctly
  }

  std::cout << "Socket bound to port : " << PORT << "\n";

  int listening = listen(socket_fd, BACKLOG);
  if (listening != 0)
  {
    // Handle error, shutdown program correctly
  }
  std::cout << "Main socket (fd : " << socket_fd << ") now listening for incoming messages";

  sockaddr_storage client_addr_info {};
  socklen_t client_addr_info_size = sizeof(client_addr_info);

  while (true) {
    int new_socket_fd  = accept(socket_fd, (struct sockaddr*)&client_addr_info, &client_addr_info_size);
    if (new_socket_fd == -1)
    {
      // Handle error, shutdown program correctly
    }
    // NEXT SESSION :parse the received data according to to-be-defined procotol, print the result. 
    // Create a client server to connect to the socket and send data

    std::cout << "New connexion accepted, message hadling socket file descriptor : " << new_socket_fd << "\n";

    while(true)
    {
      char buffer[BUFFER_SIZE] {0};
      int bytes_received = recv(new_socket_fd, buffer, sizeof(buffer), 0);
      if (bytes_received == 0)
      {
        // Client disconnected
        // Handle properly
      }

      if (bytes_received == -1)
      {
        // Handle error, do not shut down entirely, keep trying to receive message but log error
        close(new_socket_fd);
        continue;
      }

      std::string stream_buffer;
      stream_buffer += buffer;

      auto newline_pos = stream_buffer.find('\n');
      if (newline_pos == std::string::npos)
      {
        continue;
      }

      std::string message = stream_buffer.substr(0, newline_pos);
      stream_buffer.erase(0, newline_pos + 1);

      std::cout << "Message received : " << message << std::endl; 

      const std::string validation_msg = "Last message treated :" + message + "\n";

      send(new_socket_fd, validation_msg.c_str(), validation_msg.length(), 0);

      close(new_socket_fd);
    }
    
  }
 
  return EXIT_SUCCESS;
}
