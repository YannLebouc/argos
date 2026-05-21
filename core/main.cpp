#include <sys/socket.h>


int main()
{
  // Be sure to understand and write down what a "file descriptor" is
   int socketfd = socket(AF_INET, SOCK_STREAM, 0);  
   if (socketfd == -1)
   {
     // Define error handling stategy, errors vs exceptions
   }

}
