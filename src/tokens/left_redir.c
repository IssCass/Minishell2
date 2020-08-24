/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include <fcntl.h>
#include <stdlib.h>
#include "minishell2.h"

void process_left_redir(t_minishell *minishell, char *cmd, int fdin, int fdout)
{
    (void)(fdin);
    char **array = my_str_to_word_array(cmd, "<", 0);
    int fd_file;
    char *file = NULL;

    file = useless_spaces(array[1]);
    fd_file = open(file, O_RDONLY);
    if (fd_file == -1) {
        write(2, file, my_strlen(file));
        write(2, ": No such file or directory.\n", 29);
        free_tab(array);
        free(file);
        return;
    }
    process_cmd(minishell, array[0], fd_file, fdout);
}