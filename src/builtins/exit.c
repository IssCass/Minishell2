/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"
#include <unistd.h>
#include <stdlib.h>

int loop_check_exit(char **input)
{
    int i;

    for (i = 1; input[1][i]; i++) {
        if ((input[1][0] >= '0' && input[1][0] <= '9') &&
            !(input[1][i] >= '0' && input[1][i] <= '9')) {
            write(2, "exit: Badly formed number.\n", 27);
            return (1);
        }
    }
    return (0);
}

void exit_shell(t_minishell *minishell, char **input)
{
    if (input[1] != NULL) {
        if (loop_check_exit(input) == 1)
            return;
        if (!(input[1][0] >= '0' && input[1][0] <= '9')) {
            write(2, "exit: Expression Syntax.\n", 25);
            return;
        }
        free_all(minishell);
        my_printf("exit\n");
        exit(my_array_to_int(input[1]));
    } else {
        free_all(minishell);
        my_printf("exit\n");
        exit(0);
    }
}