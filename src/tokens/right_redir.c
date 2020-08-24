/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"
#include <unistd.h>
#include <fcntl.h>

int create_file(char *name, int flags)
{
    int fd = open(name, flags, 0666);
    return fd;
}

void right_redir(t_minishell *minishell, char *cmd, int fdout, int flags)
{
    char **tab = NULL;
    int fd;
    char *name;

    tab = my_str_to_word_array(cmd, ">", 0);
    if (my_strlen(tab[1]) > 255) {
        free_tab(tab);
        write(2, "File name too long.\n", 20);
        return;
    }
    name = useless_spaces(tab[1]);
    fd = create_file(name, flags);
    process_cmd(minishell, tab[0], fd, fdout);
    free_tab(tab);
    close(fd);
}

void process_right_redir(t_minishell *minishell, char *cmd, int fdout, int fdin)
{
    (void)(fdin);
    if (check_right_redir(cmd) == 2) {
        right_redir(minishell, cmd, fdout, O_WRONLY | O_CREAT | O_APPEND);
    } else if (check_right_redir(cmd) == 1) {
        write(2, "Ambiguous output redirect.\n", 27);
        return;
    } else
        right_redir(minishell, cmd, fdout, O_WRONLY | O_CREAT);
}
