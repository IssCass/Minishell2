/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"
#include <stdlib.h>
#include <unistd.h>

int check_error_setenv(char *name)
{
    if (!((name[0] >= 'a' && name[0] <= 'z') ||
        (name[0] >= 'A' && name[0] <= 'Z') || name[0] == '_')) {
        write(2, "setenv: Variable name must begin with a letter.\n", 49);
        return (1);
    }
    for (int i = 0; name[i]; i++) {
        if (!((name[i] >= 'a' && name[i] <= 'z') ||
            (name[i] >= 'A' && name[i] <= 'Z') ||
            (name[i] >= '0' && name[i] <= '9'))) {
            write(2,
                "setenv: Variable name must contain alphanumeric characters.\n",
                60);
        }
    }
    return (0);
}

char **set_env_new(t_minishell *minishell, char *name, char *value)
{
    int i;
    int x;
    char *new = set_env_already(name, value);
    char **new_env;

    for (i = 0; minishell->envp[i]; i++);
    new_env = malloc(sizeof(char *) * (i + 2));
    for (x = 0; minishell->envp[x]; x++)
        new_env[x] = my_strdup(minishell->envp[x]);
    new_env[x] = new;
    new_env[++x] = NULL;
    return (new_env);
}

char *set_env_already(char *name, char *value)
{
    char *new;

    new = my_strcpy(name);
    new = my_strcat(new, "=");
    new = my_strcat(new, value);
    return (new);
}

void set_env(t_minishell *minishell, char *name, char *value)
{
    if (check_error_setenv(name) == 1)
        return;
    for (int i = 0; minishell->envp[i]; i++) {
        if ((search_var(minishell, name) == 1) &&
            (my_strncmp(minishell->envp[i], name, my_strlen(name))) == 0) {
            minishell->envp[i] = set_env_already(name, value);
            break;
        }
        if (search_var(minishell, name) == 0) {
            minishell->envp = set_env_new(minishell, name, value);
            break;
        }
    }
}