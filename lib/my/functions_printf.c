/*
** EPITECH PROJECT, 2019
** functions.c
** File description:
** all functions for flags
*/

#include "../../include/my.h"
#include "../../include/my_printf.h"
#include <stdarg.h>

void tp_c(va_list list)
{
    my_putchar(va_arg(list, int));
}

void tp_i(va_list list)
{
    my_put_nbr(va_arg(list, int));
}

void tp_s(va_list list)
{
    my_putstr(va_arg(list, char *));
}

void tp_o(va_list list)
{
    convert_base(va_arg(list, unsigned int), OCT);
}

void tp_xmin(va_list list)
{
    convert_base(va_arg(list, unsigned int), HEXAMIN);
}
