#include <cstring>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>

int main()
{
  constexpr int PORT = 8080;
  constexpr int BACKLOG = 5;
  // First socket implementation will be manual and minimalistic for speed and educational purpose
  // Second version will use the modern posix API with getaddrinfo() etc... 

  // Be sure to understand and write down what a "file descriptor" is
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);  
  if (socket_fd == -1)
  {
    // Define error handling stategy, errors vs exceptions
    // Program should exit on failure here
  }

  sockaddr_in server_socket_addr {};
  server_socket_addr.sin_family = AF_INET;
  server_socket_addr.sin_port = htons(PORT);
  server_socket_addr.sin_addr.s_addr = INADDR_ANY;

  int bound = bind(socket_fd, (struct sockaddr*)&server_socket_addr, sizeof(server_socket_addr));
  if (bound != 0) 
  {
    // Handle error, shutdown program correctly
  }


  int listening = listen(socket_fd, BACKLOG);
  if (listening != 0)
  {
    // Handle error, shutdown program correctly
  }

  sockaddr_storage client_addr_info {};
  socklen_t client_addr_info_size = sizeof(client_addr_info);

  int new_socket_fd  = accept(socket_fd, (struct sockaddr*)&client_addr_info, &client_addr_info_size);
  if (new_socket_fd == -1)
  {
    // Handle error, shutdown program correctly
  }
  // NEXT SESSION : Receive data from client (recv()), parse it according to to-be-defined procotol, print the result. 
    
}
