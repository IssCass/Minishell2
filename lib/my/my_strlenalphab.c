/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** task03
*/

int my_strlenalphab(char const *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0'){
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z'))
            j++;
        i++;
    }
    return (j);
}