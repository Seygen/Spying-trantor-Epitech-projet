/*
** EPITECH PROJECT, 2018
** socket
** File description:
** !
*/

#include "socket.h"

int sock_connect(char const *ip, int const port, char const *prototype)
{
    proto_t *proto;
    socket_t sock;
    sockaddr_in_t sin;

    proto = getprotobyname(prototype);
    sock = socket(AF_INET, SOCK_STREAM, proto->p_proto);
    if (proto == 0 || sock == -1)
    {
        fprintf(stderr, "Error : socket()\n");
        return (-1);
    }
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = inet_addr(ip);
    if (connect(sock, (sockaddr_t *)&sin, sizeof(sin)) == -1)
    {
        close(sock);
        fprintf(stderr, "Error : connect()\n");
        return (-1);
    }
    return (sock);
}

void sock_send(socket_t sock, char *buff)
{
    dprintf(sock, "%s\n", buff);
}

char *sock_recv(socket_t sock)
{
    char *buff;

    buff = get_next_line(sock);
    return (buff);
}
