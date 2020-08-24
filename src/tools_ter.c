/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"
#include <unistd.h>
#include <stdlib.h>

int check_just_tokens(char *cmd)
{
    int size = my_strlen(cmd);
    int pipes = 0;
    int redir = 0;

    for (int i = 0; cmd[i]; i++) {
        if (cmd[i] == '|')
            pipes++;
        if (cmd[i] == '<' || cmd[i] == '>')
            redir++;
    }
    if (pipes == size) {
        write(2, "Invalid null command.\n", 22);
        return 1;
    }
    if (redir == size) {
        write(2, "Missing name for redirect.\n", 27);
        return 1;
    }
    return 0;
}

int check_right_redir(char *cmd)
{
    int i = 0;
    int nb = 0;

    for (; cmd[i]; i++) {
        if (cmd[i] == '>' && cmd[i + 1] == '>')
            return 2;
        else if (cmd[i] == '>')
            nb++;
    }
    if (nb > 1)
        return 1;
    return 0;
}

char *useless_spaces(char *str)
{
    char *res = NULL;
    int i;
    int j;

    for (i = 0; str[i] == ' ' || str[i] == '\t'; i++);
    res = malloc(sizeof(char) * (my_strlen(str) - i + 1));
    for (j = 0; str[i]; i++) {
        if (str[i] != ' ')
            res[j++] = str[i];
    }
    res[j] = '\0';
    return res;
}