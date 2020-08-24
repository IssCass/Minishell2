/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"
#include <unistd.h>

void exec_cmd_pipes(t_minishell *minishell, char **cmd_array, int fdin,
    int fdout)
{
    int x = 0;
    int pipe_fd[2];

    for (; x < size_tab(cmd_array) - 1; x++) {
        pipe(pipe_fd);
        process_cmd(minishell, cmd_array[x], fdin, pipe_fd[1]);
        close(pipe_fd[1]);
        fdin = pipe_fd[0];
    }
    if (fdin != 0)
        dup2(fdin, 0);
    process_cmd(minishell, cmd_array[x], fdin, fdout);
    loop_wait(minishell, minishell->pid);
}

void process_pipes(t_minishell *minishell, char *cmd, int fdin, int fdout)
{
    int backup_fdin = dup(STDIN_FILENO);
    int backup_fdout = dup(STDOUT_FILENO);
    char **cmd_array = my_str_to_word_array(cmd, "|", 0);

    minishell->pipe += 1;
    exec_cmd_pipes(minishell, cmd_array, fdin, fdout);
    dup2(backup_fdin, fdin);
    dup2(backup_fdout, fdout);
    free_tab(cmd_array);
}