#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

void main(int argc, char *argv[]) {
  struct addrinfo hints, *res;
  struct sockaddr_storage cli;
  char buf[81], host[NI_MAXHOST], serv[NI_MAXSERV];
  hints.ai_flags = AI_PASSIVE;
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_DGRAM;
  hints.ai_protocol = 0;
  getaddrinfo(argv[1], argv[2], &hints, &res);
  int sd = socket(res‐>ai_family, res‐>ai_socktype, 0);

  bind(sd,(struct sockaddr *)res‐>ai_addr, res‐>ai_addrlen);
  freeaddrinfo(res);
  while (1) {
    socklen_t clen = sizeof(cli);
    int c = recvfrom(sd, buf, 80, 0,
      (struct sockaddr *) &cli, &clen);
      getnameinfo((struct sockaddr *) &cli, clen, host,
      NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST);
      printf("%s %s\n", host, serv);
      sendto(sd, buf, c, 0, (struct sockaddr *)&cli, clen);
    }
  }
