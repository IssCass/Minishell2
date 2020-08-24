/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"
#include "stdlib.h"

void free_all(t_minishell *minishell)
{
    free_tab(minishell->path);
    free_tab(minishell->envp);
    free(minishell);
}

int my_str_is_equal(char *s1, char *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    int count = 0;

    for (int i = 0; s1[i]; i++) {
        if (s1[i] == s2[i])
            count++;
    }
    if (count == len1 && count == len2)
        return (0);
    return (1);
}

int search_var(t_minishell *minishell, char *name)
{
    for (int i = 0; minishell->envp[i]; i++) {
        if ((my_strncmp(minishell->envp[i], name, my_strlen(name))) == 0)
            return (1);
    }
    return (0);
}

char *pars_arg(char *cmd)
{
    int len = my_strlen(cmd);
    char *string = malloc(sizeof(char) * (len + 1));
    int y = 0;

    for (int i = 0; cmd[i]; i++) {
        if (cmd[i] == '\"' || cmd[i] == '\'')
            i++;
        string[y] = cmd[i];
        y++;
    }
    string[y] = '\0';
    free(cmd);
    return (string);
}

char *rm_name_var(char *str)
{
    int x;
    int i;
    int j;
    char *path_mod;

    for (i = 0; str[i] != '/'; i++);
    for (j = i; str[j]; j++);
    path_mod = malloc(sizeof(char) * (j + 1));
    for (x = 0; str[i]; i++, x++) {
        path_mod[x] = str[i];
    }
    path_mod[x] = '\0';
    return (path_mod);
}