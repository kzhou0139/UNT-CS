// Kelly Zhou
// 3600.002
// 25 April 2023
/* client program in client/server model that uses Linux
   sockets for a UDP "ping" utility*/

// include directives
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define DATA "[client]: PING\n"

int main(int argc, char *argv[]) {
  if (argc == 3) { // checks to make sure 3 arguments are passed
    // initialize variables
    int sock, errnum;
    struct sockaddr_in name;
    struct addrinfo hints, *result, *rp;
    char buf[1024];

    // create socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
      perror("opening datagram socket");
      exit(1);
    }

    // set address info
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = 0;
    hints.ai_protocol = 0;
    errnum = getaddrinfo(argv[1], argv[2], &hints, &result);
    // checks if there are errors in the address info
    if (errnum != 0) {
      fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errnum));
      exit(1);
    }

    // initialize variables
    rp = result;
    double max = 0; // max elapsed time
    double min = 100; // min elapsed time
    double sum = 0;
    int recNum = 0; // count number of received data
    // for loop for client to send and receive messages 10 times
    for (int i = 1; i < 11; i++) {
      clock_t start = clock(); // start timing
      struct timeval tVal;
      tVal.tv_sec = 1;
      tVal.tv_usec = 0;

      // erases data in name
      bzero(&name, sizeof(name));
      memcpy((char*)&name.sin_addr, (char*)&((struct sockaddr_in*)rp->ai_addr)->sin_addr, sizeof(name.sin_addr));
      // set name info
      name.sin_family = AF_INET;
      name.sin_port = htons(atoi(argv[2]));

      int length = sizeof(name);
      // send DATA to server
      if (sendto(sock, DATA, strlen(DATA), MSG_WAITALL, (struct sockaddr*)&name, length) == -1) {
          perror("sending datagram message");
          continue;
      }
      printf("\t%d: Sent... ", i);

      // receive data from server. timeout if more than a second
      int timeout = setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tVal, sizeof(struct timeval));
      if (recvfrom(sock, buf, 1024, MSG_WAITALL, (struct sockaddr*)&name, &length) == -1) {
          printf("Timed Out\n");
          continue;
      }

      clock_t end = clock(); // end timing
      double elapsed = ((double)(end-start) / CLOCKS_PER_SEC) * 1000; // calculate elapsed time
      if (elapsed > max) // if elapsed time is greater than the max elapsed time, replace max with elapsed
        max = elapsed;
      if (elapsed < min) // if elapsed time is less than the min elapsed time, replace min with elapsed
        min = elapsed;
      sum += elapsed;
      printf("RTT=%.6f ms\n", elapsed);
      recNum++; // increase number of received data
      sleep(1);
    }

    int lossPerc = (10 - recNum) * 10; // calculate data loss percentage
    double avg = sum / recNum; // find the average of elapsed times

    // print out the package loss statistics
    printf("\t10 pkts xmited, %d pkts rcvd, %d%% pkt loss\n", recNum, lossPerc);
    printf("\tmin: %.6f ms, max: %.6f ms, avg: %.6f ms\n", min, max, avg);

    // free address info and close socket
    freeaddrinfo(result);
    close(sock);
  }
  else // if there are not 3 arguments, print out utility statement
    printf("usage: ./minor4cli <hostname> <port>\n");

  return 0;
}
