/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** my_strcmp
*/

int my_strlen(char *str);

int my_strcmp(char *s1, char *s2)
{
    int len = my_strlen(s2);
    int i = 0;
    int count = 0;

    for (; s1[i]; i++) {
        if (s1[i] == s2[i]){
            count++;}
    }
    if (count == len)
        return (0);
    return (1);
}
