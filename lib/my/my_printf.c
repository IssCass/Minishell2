/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** my_printf
*/

#include "../../include/my.h"
#include "../../include/my_printf.h"
#include <stdarg.h>
#include <stdio.h>

int flag_imp(char c)
{
    char av[] = "cidsoxXbSu%";
    int j;

    for (j = 0; av[j]; j++) {
        if (av[j] == c){
            return (1);
        }
    }
    return (0);
}

int num_flags(char c)
{
    char av[] = "cidsoxXbSu%";
    int j;

    for (j = 0; av[j]; j++) {
        if (av[j] == c){
            return (j);
        }
    }
    return (0);
}

void function_array(va_list list, int j)
{
    func array[11] = {&tp_c, &tp_i, &tp_i, &tp_s, &tp_o, &tp_xmin, &tp_xcap,
        &tp_bin, &tp_scap, &tp_u, &tp_percent};
    (array[j])(list);
}

void my_printf(char *str, ...)
{
    va_list list;

    va_start(list, str);
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == '%' && flag_imp(str[i + 1])){
            i++;
            j = num_flags(str[i]);
            function_array(list, j);
        }
        else
            my_putchar(str[i]);
    }
    va_end(list);
}