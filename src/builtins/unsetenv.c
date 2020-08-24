/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"
#include <unistd.h>
#include <stdlib.h>

void unset_env_redir(t_minishell *minishell, char **input)
{
    if ((my_strncmp(input[0], "unsetenv", 8) == 0) && input[1] == NULL) {
        my_printf("unsetenv: Too few arguments\n");
        return;
    }
    for (int i = 1; input[i] && (search_var(minishell, input[i]) == 1); i++)
        minishell->envp = unset_env(minishell, input[i]);
}

char **unset_env(t_minishell *minishell, char *name)
{
    int i;
    int x;
    int y;
    char **new_env;

    for (i = 0; minishell->envp[i]; i++);
    new_env = malloc(sizeof(char *) * i);
    for (x = 0, y = 0; minishell->envp[x]; x++) {
        if ((my_strncmp(minishell->envp[x], name, my_strlen(name))) != 0) {
            new_env[y] = my_strdup(minishell->envp[x]);
            y++;
        }
    }
    new_env[y] = NULL;
    return (new_env);
}