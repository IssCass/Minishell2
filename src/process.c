/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include <minishell2.h>
#include <unistd.h>

void basic_process(t_minishell *minishell, char *cmd, int fdin, int fdout)
{
    char **arg;

    if ((arg = my_str_to_word_array(cmd, " \t\n", 0)) == NULL)
        return;
    fptr_builtins(minishell, arg, fdin, fdout);
    free_tab(arg);
}

void process_cmd(t_minishell *minishell, char *cmd, int fdin, int fdout)
{
    minishell->path = new_get_path(minishell);
    void ((*tab[5])(t_minishell *, char *, int, int)) = {&process_semicolons,
        &process_pipes, &process_right_redir, &process_left_redir,
        &basic_process};
    char *separators[5] = {";", "|", ">", "<", NULL};
    int nb_sep = 0;
    int i = 0;

    for (; separators[i]; i++) {
        if (check_char(cmd, separators[i][0]) != 0) {
            nb_sep += 1;
            (tab[i])(minishell, cmd, fdin, fdout);
            break;
        }
    }
    if (nb_sep == 0)
        (tab[4])(minishell, cmd, fdin, fdout);
}