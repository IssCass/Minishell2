/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"
#include <unistd.h>

void redirect_cd_two(t_minishell *minishell, char **input, int i)
{
    if (my_str_is_equal(input[1], "-") == 0 && i == 2)
        cd_tiret(minishell);
    else if (my_str_is_equal(input[1], "/") == 0)
        cd_slash(minishell);
    else
        cd_builtin(minishell, input[1]);
}

void redirect_cd(t_minishell *minishell, char **input)
{
    int i;

    for (i = 0; input[i]; i++);
    if (i > 2) {
        write(2, "cd: Too many arguments.\n", 24);
        return;
    } else if (i == 1 || (my_str_is_equal(input[1], "~") == 0))
        cd_wtout_arg(minishell);
    else
        redirect_cd_two(minishell, input, i);
}

void set_env_redir(t_minishell *minishell, char **input)
{
    if (input[3] != NULL && input[2] != NULL) {
        write(2, "setenv: Too many arguments.\n", 24);
        return;
    }
    if ((my_strcmp(input[0], "setenv") == 0) && input[1] == NULL)
        env(minishell, NULL);
    else if (input[2] == NULL)
        set_env(minishell, input[1], "");
    else
        set_env(minishell, input[1], input[2]);
}