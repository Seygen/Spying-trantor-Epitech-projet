/*
** EPITECH PROJECT, 2018
** Boostrap
** File description:
** Client Trantor
*/

#include "spying.h"

int init_client(socket_t sock, int port, char *team_name)
{
  char *buffer;
  sock_recv(sock);
  sock_send(sock, team_name);
  buffer = sock_recv(sock);
  if (strcmp(buffer, "ko") == 0)
  {
    printf("Cannot chill with the server so... My name's is jeff\n");
    return -1;
  }
  else
  {
    sock_recv(sock);
    printf("connected to a drone from  %s on port %d \n", team_name, port);
  }
  free(buffer);
  return 0;
}

int main(int argc, char **argv)
{
  socket_t sock;
  (void)argc;

  sock = sock_connect(argv[1], atoi(argv[2]), "TCP");
  if (init_client(sock, atoi(argv[2]), argv[3]) == -1)
  {
    return 84;
  }
  if (run_client(sock) == -1)
  {
    return 84;
  }
  return 0;
}
