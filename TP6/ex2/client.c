#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>

#include "../utils_v2.h"

#define HOSTNAME "ochoquet.be"
#define SIZE 16



/**
 * PRE: serverIP : a valid IP address
 *      serverPort: a valid port number
 * POST: on success, connects a client socket to serverIP:serverPort
 *       on failure, displays error cause and quits the program
 * RES: return socket file descriptor
 */
int initSocketClient(char * serverIP, int serverPort)
{
  int sockfd = ssocket();
  sconnect(serverIP, serverPort, sockfd);

  return sockfd;
}

int main(int argc, char **argv)
{
    int fd = sopen("./sitemap.txt", O_RDONLY, 0);
    char **urls=readFileToTable(fd);
    sclose(fd);

    char serverIP[SIZE];
    hostname_to_ip(HOSTNAME, serverIP);
  
    for (int i = 0; urls[i] != NULL; i++) {

      int sockfd = initSocketClient(serverIP, 80);

      char request[1024];
      sprintf(request, "GET %s HTTP/1.1\r\nHost: ochoquet.be\r\nConnection: close\r\n\r\n", urls[i]);    
      nwrite(sockfd, request, strlen(request));


      // pr le nom du fichier
      char *basename = strrchr(urls[i], '/');
      if (basename) {
          basename++; 
      } else {
          basename = "page.html";
      }

      int outfd = sopen(basename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

      char buffer[1024];
      int n;
      while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
          write(outfd, buffer, n);
      }

      sclose(outfd);
      sclose(sockfd);
    }
    return 0;

}
