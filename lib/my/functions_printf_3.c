/*
** EPITECH PROJECT, 2019
** functions.c
** File description:
** all functions for flags
*/

#include "../../include/my.h"
#include "../../include/my_printf.h"
#include <stdarg.h>

void put_scapzero(char str)
{
    if (str < 8)
        my_putchar('0');
    if (str < 64)
        my_putchar('0');
}

void put_scap(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++){
        if (str[i] < ' ' || str[i] == 127){
            my_putstr("\\");
            put_scapzero(str[i]);
            convert_base(str[i], OCT);
        } else
            my_putchar(str[i]);
    }
}

void tp_u(va_list list)
{
    my_put_unsigned(va_arg(list, unsigned int));
}