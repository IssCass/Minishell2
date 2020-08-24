/*
** EPITECH PROJECT, 2024
** .
** File description:
** Created by Enzo Ventura
*/

#include "../../include/my.h"
#include <stdlib.h>
#include <unistd.h>

char *realloc_str(char *str, int len)
{
    char *new_str = malloc(sizeof(char) * (len + 1));
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        new_str[i] = str[i];
    new_str[i] = '\0';
    return (new_str);
}

char one_char(int fd)
{
    static int count = -1;
    static int len = 0;
    static char buffer[READ_SIZE];

    count++;
    if (len == 0) {
        len = read(fd, buffer, READ_SIZE);
        buffer[len] = '\0';
        if (buffer[0] == '\0')
            return (0);
        count = 0;
    }
    len--;
    return (buffer[count]);
}

char *loop(int fd, char charac)
{
    char *res = malloc(sizeof(char) * (READ_SIZE + 1));
    int i = 0;

    if (res == NULL)
        return NULL;
    while (charac != '\n' && charac != '\0') {
        res[i] = charac;
        charac = one_char(fd);
        i++;
        if (i % READ_SIZE == 0) {
            res[i] = '\0';
            res = realloc_str(res, i + READ_SIZE);
        }
    }
    res[i] = '\0';
    return (res);
}

char *get_next_line(int fd)
{
    char charac = one_char(fd);

    if (charac == 0)
        return (NULL);
    return (loop(fd, charac));
}
