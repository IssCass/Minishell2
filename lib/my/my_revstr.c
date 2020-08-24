/*
** EPITECH PROJECT, 2019
** my_revstr.c$
** File description:
** Task03
*/

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    int p = 0;
    char *string = str;
    char tamp;

    while (str[i] != '\0'){
        i++;
    }
    i--;
    p = i / 2;

    while (i > p){
        tamp = str [j];
        string[j] = str[i];
        string[i] = tamp;
        j++;
        i--;
    }
    return (string);
}
