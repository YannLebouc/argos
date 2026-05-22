#include <cstddef>
#include <cstring>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>

int main()
{
  // Be sure to understand and write down what a "file descriptor" is
   int socketfd = socket(AF_INET, SOCK_STREAM, 0);  
   if (socketfd == -1)
   {
     // Define error handling stategy, errors vs exceptions
     // Program should exit on failure here
   }

   
  int status;
  struct addrinfo hints;
  struct addrinfo *servinfo;
  std::memset(&hints, 0, sizeof hints);

  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  status = getaddrinfo(NULL, "8080", &hints, &servinfo );
  if (status != 0)
  {
    // Error handling to be defined
    // Program should exit on failure
  }


  // bind()

  // send()
  // recv()
   

  // Do everything needed with servinfo, then free it
  freeaddrinfo(servinfo);

}
