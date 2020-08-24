/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void cd_slash(t_minishell *minishell)
{
    char *path = "/";

    cd_builtin(minishell, path);
}

void cd_tiret(t_minishell *minishell)
{
    char *old_pwd = NULL;
    char *path = NULL;

    if (search_var(minishell, "OLDPWD") == 0) {
        write(2, ": No such file or directory.\n", 29);
        return;
    }
    if (minishell->count_cd == 0) {
        write(2, ": No such file or directory.\n", 29);
        return;
    }
    old_pwd = my_get_line_env(minishell, "OLDPWD");
    path = rm_name_var(old_pwd);
    cd_builtin(minishell, path);
}

void cd_wtout_arg(t_minishell *minishell)
{
    char *home = NULL;
    char *path_home = NULL;

    if (search_var(minishell, "HOME") == 0)
        return;
    home = my_get_line_env(minishell, "HOME");
    path_home = rm_name_var(home);
    cd_builtin(minishell, path_home);
}

void cd_builtin(t_minishell *minishell, char *dir)
{
    char *old_pwd = NULL;
    char *new_pwd = NULL;
    char *str = NULL;

    old_pwd = getcwd(NULL, 0);
    if (chdir(dir) < 0) {
        str = strerror(errno);
        write(2, dir, my_strlen(dir));
        write(2, ": ", 2);
        write(2, str, my_strlen(str));
        write(2, ".\n", 2);
        return;
    }
    new_pwd = getcwd(NULL, 0);
    set_env(minishell, "OLDPWD", old_pwd);
    set_env(minishell, "PWD", new_pwd);
    free(old_pwd);
    free(new_pwd);
    minishell->count_cd++;
}