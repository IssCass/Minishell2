/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** task03
*/

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i]; i++);
    return (i);
}
