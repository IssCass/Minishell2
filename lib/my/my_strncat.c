/*
** EPITECH PROJECT, 2019
** my_strncat.c
** File description:
** task03
*/

char *my_strncat(char *dest, const char *src, int n)
{
    int dest_length;
    int i;

    for (dest_length = 0; dest[dest_length] != '\0'; dest_length++);
    for (i = 0 ; i < n && src[i] != '\0' ; i++)
        dest[dest_length + i] = src[i];
    dest[dest_length + i] = '\0';

    return (dest);
}
