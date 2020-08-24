/*
** EPITECH PROJECT, 2019
** function2.c
** File description:
** all functions for flags
*/

#include "../../include/my.h"
#include "../../include/my_printf.h"
#include <stdarg.h>

void tp_scap(va_list list)
{
    char *str = va_arg(list, char *);
    put_scap(str);
}

void tp_xcap(va_list list)
{
    convert_base(va_arg(list, unsigned int), HEXACAP);
}

void tp_bin(va_list list)
{
    convert_base(va_arg(list, unsigned int), BIN);
}

void tp_percent(va_list list)
{
    UNUSED (list);
    my_putchar('%');
}

void convert_base(unsigned int nb, char *base)
{
    int len = my_strlen(base);
    unsigned int modul = nb % len;
    unsigned int result = (nb - modul) / len;

    if (result)
        convert_base(result, base);
    my_putchar(base[modul]);
}