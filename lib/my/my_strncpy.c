/*
** EPITECH PROJECT, 2019
** my_strncpy.c
** File description:
** Task02
*/

char *my_strcpy(char *src);

int my_strlen(char const *src);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    if (my_strlen(src) < n){
        my_strcpy(src);
        return (dest);
    }
    for (i = 0; src[i] != '\0' && i < n; i++)
        dest[i] = src [i];
    dest[i] = '\0';
    return (dest);
}
