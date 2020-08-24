/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** putstr
*/

void my_putchar(char c);

char my_putstr(char const *str)
{
    for (int i = 0; str [i] != '\0'; i++)
        my_putchar(str[i]);
}
