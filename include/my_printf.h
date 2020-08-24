/*
** EPITECH PROJECT, 2019
** my_printf.h
** File description:
** .h my_printf
*/

#include <stdarg.h>

#ifndef MY_PRINT_H_
#define MY_PRINT_H_
#define HEXAMIN "0123456789abcdef"
#define HEXACAP "0123456789ABCDEF"
#define OCT "01234567"
#define BIN "01"
#define UNUSED(x) (void)(x)

typedef void (*func)(va_list);

void tp_c(va_list list);

void tp_i(va_list list);

void tp_s(va_list list);

void tp_o(va_list list);

void tp_bin(va_list list);

void tp_xmin(va_list list);

void tp_xcap(va_list list);

void tp_percent(va_list list);

void tp_scap(va_list list);

void tp_u(va_list list);

void put_scap(char *str);

void convert_base(unsigned int nb, char *base);

void my_printf(char *str, ...);

#endif