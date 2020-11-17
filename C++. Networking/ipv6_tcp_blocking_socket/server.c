#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <Winsock2.h>
#include <Ws2tcpip.h>
#include <Windows.h>
#define WIN32_LEAN_AND_MEAN
#pragma comment (lib, "Ws2_32.lib")
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#endif

#define CLIENT_QUEUE_LEN 10
#define SERVER_PORT 7002

int main(void)
{
   int listen_sock_fd = -1, client_sock_fd = -1;
   struct sockaddr_in6 server_addr, client_addr;
   socklen_t client_addr_len;
   char str_addr[INET6_ADDRSTRLEN];
   int ret, flag;
   char ch;

#ifdef _WIN32
   WSADATA wsaData;
   if (WSAStartup(MAKEWORD(2, 2), &wsaData))
   {
      perror("WSAStartup");
      return 1;
   }
#endif

   /* Create socket for listening (client requests) */
   listen_sock_fd = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);
   if (listen_sock_fd == -1)
   {
      perror("socket()");
      return EXIT_FAILURE;
   }

   /* Set socket to reuse address */
   flag = 1;
   ret = setsockopt(listen_sock_fd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));
   if (ret == -1)
   {
      perror("setsockopt()");
      return EXIT_FAILURE;
   }

   server_addr.sin6_family = AF_INET6;
   server_addr.sin6_addr = in6addr_any;
   server_addr.sin6_port = htons(SERVER_PORT);

   /* Bind address and socket together */
   ret = bind(listen_sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr));
   if (ret == -1)
   {
      perror("bind()");
      closesocket(listen_sock_fd);
      return EXIT_FAILURE;
   }

   /* Create listening queue (client requests) */
   ret = listen(listen_sock_fd, CLIENT_QUEUE_LEN);
   if (ret == -1)
   {
      perror("listen()");
      closesocket(listen_sock_fd);
      return EXIT_FAILURE;
   }

   client_addr_len = sizeof(client_addr);

   while (1)
   {
      /* Do TCP handshake with client */
      client_sock_fd = accept(listen_sock_fd,
                              (struct sockaddr *) &client_addr,
                              &client_addr_len);
      if (client_sock_fd == -1)
      {
         perror("accept()");
         closesocket(listen_sock_fd);
         return EXIT_FAILURE;
      }

      inet_ntop(AF_INET6, &(client_addr.sin6_addr), str_addr, sizeof(str_addr));
      printf("New connection from: %s:%d ...\n",
             str_addr,
             ntohs(client_addr.sin6_port));

      /* Wait for data from client */
      ret = read(client_sock_fd, &ch, 1);
      if (ret == -1)
      {
         perror("read()");
         closesocket(client_sock_fd);
         continue;
      }

      /* Do very useful thing with received data :-) */
      ch++;

      /* Send response to client */
      ret = write(client_sock_fd, &ch, 1);
      if (ret == -1)
      {
         perror("write()");
         closesocket(client_sock_fd);
         continue;
      }

      /* Do TCP teardown */
      ret = closesocket(client_sock_fd);
      if (ret == -1)
      {
         perror("close()");
         client_sock_fd = -1;
      }

      printf("Connection closed\n");
   }

#ifdef _WIN32
   WSACleanup();
#endif

   return EXIT_SUCCESS;
}
