/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"
#include <wait.h>
#include <string.h>
#include <unistd.h>

void return_value(t_minishell *minishell, int value)
{
    char *msg;

    if (WIFEXITED(value)) {
        minishell->return_value = WEXITSTATUS(value);
        return;
    }
    if (WIFSIGNALED(value)) {
        msg = strsignal(WTERMSIG(value));
        if (my_strcmp(msg, "Floating point exception") == 0)
            write(2, "Floating exception", 18);
        else
            write(2, msg, my_strlen(msg));
        if (WCOREDUMP(value))
            write(2, " (core dumped)", 14);
        write(2, "\n", 1);
        minishell->return_value = WTERMSIG(value) + 128;
        return;
    }
}