/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** Task02
*/

#ifndef MY_H_
#define MY_H_

#include "my_printf.h"
#define READ_SIZE 3

void my_putchar(char c);
int my_put_nbr(int nb);
char my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *src);
char *my_strncpy(char *dest, char  const *src, int n);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char *dest, char *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_strlenalphab(char const *str);
int my_array_to_int(char *str);
int my_strtol(char *str, char **endptr);
int my_put_unsigned(unsigned int nb);
void swap_elem(int *array, int index1, int index2);
char **my_str_to_word_array(char *str, char *characs, int start);
char *my_strdup(char *str);
char *get_next_line(int fd);
void print_tab(char **tab);
void free_tab(char **tab);

#endif
