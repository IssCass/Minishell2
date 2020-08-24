/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"

void env(t_minishell *minishell, char **input)
{
    (void)(input);
    for (int i = 0; minishell->envp[i]; i++)
        my_printf("%s\n", minishell->envp[i]);
}