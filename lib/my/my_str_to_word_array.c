/*
** EPITECH PROJECT, 2024
** PSU_minishell1_2019
** File description:
** Created by Enzo Ventura
*/

#include <stdlib.h>

int check_charac(char *characs, char now_charac)
{
    for (int i = 0; characs[i]; i++)
        if (now_charac == characs[i])
            return (1);
    return (0);
}

int len_words(char *str, int i, char *characs)
{
    int lenght = 0;

    for (; str[i] ; i++) {
        if ((check_charac(characs, str[i]) == 1) || str[i] == '\0')
            return (lenght);
        lenght++;
    }
    return (lenght);
}

int count_words(char *str, char *characs)
{
    int words = 0;
    int backup = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((check_charac(characs, str[i]) == 0) && backup == 0) {
            backup = 1;
            words++;
        }
        if (check_charac(characs, str[i]) == 1)
            backup = 0;
    }
    return (words);
}

char **my_str_to_word_array(char *str, char *characs, int start)
{
    int i = start;
    char **array = NULL;
    int x = 0;
    int y;
    int words = count_words(str, characs);

    if (words == 0)
        return (array);
    array = malloc(sizeof(char *) * (words + 1));
    for (; x < words; x++) {
        for (; check_charac(characs, str[i]) == 1; i++);
        array[x] = malloc(sizeof(char) * (len_words(str, i, characs)) + 1);
        for (y = 0; (check_charac(characs, str[i]) == 0)&& str[i]; y++, i++)
            array[x][y] = str[i];
        array[x][y] = '\0';
    }
    array[x] = NULL;
    return array;
}