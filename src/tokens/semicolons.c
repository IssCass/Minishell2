/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"

void process_semicolons(t_minishell *minishell, char *cmd, int fdin, int fdout)
{
    char **cmd_array = my_str_to_word_array(cmd, ";", 0);

    for (int i = 0; cmd_array[i]; i++)
        process_cmd(minishell, cmd_array[i], fdin, fdout);
}