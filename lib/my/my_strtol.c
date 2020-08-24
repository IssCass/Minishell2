/*
** EPITECH PROJECT, 2019
** my_strtol.c
** File description:
** getnbr + pointer
*/

#include <stdlib.h>

int my_strtol(char *str, char **endptr)
{
    int lnumb = 0;
    char c;

    while (*str == ' ')
        str++;
    c = *str;
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        str++;
    while (*str >= '0' && *str <= '9') {
        lnumb = lnumb * 10 + *str - '0';
        str++;
    }
    if (endptr != NULL)
        *endptr = str;
    if (c == '-')
        lnumb = -lnumb;
    return (lnumb);
}