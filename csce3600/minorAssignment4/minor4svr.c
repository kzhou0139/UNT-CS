// Kelly Zhou
// 3600.002
// 25 April 2023
/* server program in client/server model that uses Linux
   sockets for a UDP "ping" utility*/

// include directives
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define DATA "PONG"

int main(int argc, char *argv[]) {
  if (argc == 2) { // checks to make sure 3 arguments are passed
    // initialize variables
    int sock, length;
    struct sockaddr_in name, cli_addr;
    char buf[1024] = "PONG";

    // create socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
      perror("opening diagram socket");
      exit(1);
    }

    // erase data in name and cli_addr
    bzero (&name, sizeof(name));
    bzero (&cli_addr, sizeof(cli_addr));
    // set name info
    name.sin_family = AF_INET;
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    name.sin_port = htons(atoi(argv[1]));

    // assigns address to socket
    if (bind(sock, (struct sockaddr*)&name, sizeof(name)) == -1) {
      perror("binding datagram socket");
      exit(1);
    }

    length = sizeof(name);
    // gets socket name
    if (getsockname(sock, (struct sockaddr*)&name, &length) == -1) {
      perror("getting socket name");
      exit(1);
    }

    printf("[server]: ready to accept data...\n");

    length = sizeof(cli_addr);
    // continuously waits for client to send info
    while (1) {
      int randNum = (rand() % 10) + 1; // generates a random number between 1-10
      if (recvfrom(sock, buf, 1024, 0, (struct sockaddr*)&cli_addr, &length) == -1)
        perror("receiving datagram packet");

      if (randNum <= 3) // artifically simulates 30% packet loss
        printf("[server]: packet dropped\n");
      else { // if packet not dropped, send "PONG" back to client
        printf("[client]: PING\n");
        if (sendto(sock, DATA, sizeof DATA, 0, (struct sockaddr*)&cli_addr, length) == -1)
          perror("sending datagram packet");
      }
    }

    // close socket, exit program
    close(sock);
    exit(0);
  }
  else // if there are not 2 arguments, print out utility statement
    printf("usage: ./minor4svr <port>\n");

  return 0;
}
