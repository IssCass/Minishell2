/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sigint_hander(int signal)
{
    (void)(signal);
    (isatty(0) == 1) ? write(1, "\n$>", 3) : 0;
}

int condition_loop(char **cmd)
{
    (isatty(0) == 1) ? write(1, "$>", 2) : 0;
    if (((*cmd) = get_next_line(0)) == NULL) {
        my_printf("exit\n");
        return 1;
    }
    return 0;
}

void loopshell(t_minishell *minishell)
{
    char *cmd;

    while (condition_loop(&cmd) == 0) {
        minishell->path = new_get_path(minishell);
        if (check_cmd(cmd) == 1)
            continue;
        cmd = pars_arg(cmd);
        if (check_just_tokens(cmd) == 1)
            continue;
        minishell->pipe = 0;
        process_cmd(minishell, cmd, STDIN_FILENO, STDOUT_FILENO);
        if (check_input(cmd) == 1)
            return;
    }
}

int main(int ac, char **av, char **env)
{
    (void)(av);
    t_minishell *minishell = malloc(sizeof(t_minishell));

    if (errors(ac) == 84)
        return (84);
    init_struct(minishell);
    my_get_env(minishell, env);
    signal(SIGINT, sigint_hander);
    loopshell(minishell);
    free_all(minishell);
    return (minishell->return_value);
}