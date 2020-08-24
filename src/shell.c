/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"
#include <unistd.h>
#include <dirent.h>

int check_permission(char *str)
{
    DIR *directory = opendir(str);

    if (directory != NULL ||
        (access(str, F_OK) == 0 && access(str, W_OK) != 0 &&
            access(str, X_OK) != 0)) {
        write(2, str, my_strlen(str));
        write(2, ": Permission denied.\n", 21);
        closedir(directory);
        return 1;
    }
    closedir(directory);
    return 0;
}

void no_builtin(t_minishell *minishell, char **input, int fdin, int fdout)
{
    char *path;
    int fds[2];

    fds[0] = fdin;
    fds[1] = fdout;
    path = find_path(input[0], minishell);
    if (check_arr(input, path) == 1)
        return;
    if (check_permission(input[0]) == 1)
        return;
    exec_cmd(minishell, input, path, fds);
    simple_wait(minishell);
}

void fptr_builtins(t_minishell *minishell, char **input, int fdin, int fdout)
{
    void ((*tab[5])(t_minishell *, char **)) = {&set_env_redir,
        &unset_env_redir, &env, &exit_shell, &redirect_cd};
    char *separators[6] = {"setenv", "unsetenv", "env", "exit", "cd", NULL};
    int nb_builtins = 0;
    int i = 0;

    for (; separators[i]; i++) {
        if (my_str_is_equal(input[0], separators[i]) == 0) {
            nb_builtins += 1;
            (tab[i])(minishell, input);
            break;
        }
    }
    if (nb_builtins == 0)
        no_builtin(minishell, input, fdin, fdout);
}