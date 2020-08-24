/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** task01
*/

#include <stdlib.h>

int my_strlen(char *dest);

char *my_strcat(char *src, char *dest)
{
    int i = 0;
    int y = 0;
    int len = (my_strlen(src) + my_strlen(dest));
    char *res = malloc(sizeof(char) * len + 1);

    while (src[i] != '\0') {
        res[i] = src[i];
        i++;
    }
    while (dest[y] != '\0') {
        res[i] = dest[y];
        i++;
        y++;
    }
    res[i] = '\0';
    return (res);
}