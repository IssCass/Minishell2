/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"
#include <stdlib.h>

int check_char(char *str, char c)
{
    int nb_char = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            nb_char++;
    }
    return nb_char;
}

int check_input(char *input)
{
    int nb = 0;
    for (int i = 0; input[i]; i++) {
        if (input[i] == '\t' || input[i] == '\n' || input[i] == ' ')
            nb++;
    }
    if (nb == my_strlen(input))
        return (1);
    return (0);
}

int check_cmd(char *cmd)
{
    int nb_quote = 0;
    int nb_dquote = 0;

    for (int i = 0; cmd[i]; i++) {
        if (cmd[i] == '\'')
            nb_quote++;
        else if (cmd[i] == '"')
            nb_dquote++;
    }
    if ((nb_dquote % 2) != 0) {
        my_printf("Unmatched '\"'.\n");
        return (1);
    }
    if ((nb_quote % 2) != 0) {
        my_printf("Unmatched '\''.\n");
        return (1);
    }
    return (0);
}

int check_arr(char **input, char *path)
{
    if (path == NULL) {
        my_printf("%s: Command not found.\n", input[0]);
        return (1);
    }
    return (0);
}

int size_tab(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return (i);
}