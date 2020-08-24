/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"
#include "stdlib.h"

char *my_get_line_env(t_minishell *minishell, char *name)
{
    int i;

    for (i = 0; minishell->envp[i]; i++) {
        if (my_strncmp(minishell->envp[i], name, my_strlen(name)) == 0)
            return (minishell->envp[i]);
    }
    return (NULL);
}

char **my_get_paths(t_minishell *minishell)
{
    int i;
    char **tab = NULL;

    for (i = 0; minishell->envp[i]; i++) {
        if (my_strncmp(minishell->envp[i], "PATH=", 5) == 0)
            tab = my_str_to_word_array(minishell->envp[i], ":", 5);
    }
    return (tab);
}

void my_get_env(t_minishell *minishell, char **env)
{
    int i;
    int x = 0;

    for (i = 0; env[i]; i++);
    minishell->envp = malloc(sizeof(char *) * (i + 1));
    for (x = 0; env[x]; x++) {
        minishell->envp[x] = malloc(sizeof(char) * (my_strlen(env[x]) + 1));
        minishell->envp[x] = my_strcpy(env[x]);
    }
    minishell->envp[x] = NULL;
    minishell->path = my_get_paths(minishell);
}