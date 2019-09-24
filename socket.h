/*
** EPITECH PROJECT, 2018
** drone
** File description:
** !
*/

#ifndef SOCKET_H_
# define SOCKET_H_

# include <sys/socket.h>
# include <sys/select.h>
# include <sys/types.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <string.h>
# include <netdb.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

# include "get_next_line.h"

typedef int socket_t;
typedef struct sockaddr_in sockaddr_in_t;
typedef struct sockaddr sockaddr_t;
typedef struct protoent proto_t;

int dprintf(int, const char *, ...);

int sock_connect(char const *, int const, char const *);
void sock_send(socket_t, char *);
char *sock_recv(socket_t);

#endif /* !SOCKET_H_ */
