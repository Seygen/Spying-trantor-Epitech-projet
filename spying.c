/*
** EPITECH PROJECT, 2018
** Boostrap
** File description:
** Client Trantor
*/

#include "spying.h"

int check_command(char *buff)
{
    char *cmd[7] = {"forward", "right", "left",
                    "look", "inventory", "drop", "take"};
    int i = 0;

    while (i < 7)
    {
        if (!strncmp(buff, cmd[i], strlen(cmd[i])))
            return 0;
        i++;
    }
    printf("invalid command\n");
    return 1;
}

int run_client(socket_t sock)
{
    char *buff;
    int check;

    while (1)
    {
        do
        {
            write(0, "$>", 3);
            buff = get_next_line(STDIN_FILENO);
        } while (strlen(buff) == 0);
        check = check_command(buff);
        sock_send(sock, buff);
        free(buff);
        buff = sock_recv(sock);
        if (check == 0)
            printf("%s\n", buff);
        if (strcmp(buff, "dead") == 0)
        {
            free(buff);
            close(sock);
            return -1;
        }

        free(buff);
    }
    return 0;
}