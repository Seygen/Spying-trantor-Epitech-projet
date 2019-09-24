/*
** EPITECH PROJECT, 2018
** drone
** File description:
** !
*/

#include "get_next_line.h"

static char *add_char(char *str, const char c)
{
    char *new_str;
    int len;
    int i;

    i = 0;
    len = strlen(str);
    new_str = malloc(sizeof(char) * (len + 2));
    if (new_str == NULL)
        return (NULL);
    while (str[i] != '\0')
    {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = c;
    new_str[i + 1] = '\0';
    free(str);
    return (new_str);
}

char *get_next_line(const int fd)
{
    char buff;
    char *str;

    str = malloc(sizeof(char));
    if (str == NULL)
        return (NULL);
    str[0] = '\0';
    while (read(fd, &buff, 1) > 0)
    {
        if (buff == '\n' || buff == '\0')
            return (str);
        str = add_char(str, buff);
        if (str == NULL)
        {
            free(str);
            return (NULL);
        }
    }
    free(str);
    return (NULL);
}
