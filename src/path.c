/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"
#include "stdlib.h"
#include "unistd.h"

char **new_get_path(t_minishell *minishell)
{
    char **tab = NULL;

    if (search_var(minishell, "PATH") == 0)
        return NULL;
    else {
        if (minishell->path != NULL)
            free_tab(minishell->path);
        tab = my_get_paths(minishell);
    }
    return (tab);
}

char **fill_tab(t_minishell *minishell, char **tab)
{
    int z;
    int y;

    for (z = 0; minishell->path[z]; z++);
    tab = malloc(sizeof(char *) * (z + 1));
    for (y = 0; minishell->path[y]; y++)
        tab[y] = my_strdup(minishell->path[y]);
    tab[y] = NULL;
    return (tab);
}

char *find_path(char *cmd, t_minishell *minishell)
{
    char *path = "";
    char **tab = NULL;

    if (access(cmd, X_OK) == 0)
        return (cmd);
    if (minishell->path == NULL)
        return (NULL);
    tab = fill_tab(minishell, tab);
    for (int i = 0; tab[i]; i++) {
        path = malloc(sizeof(char) *
            (my_strlen(minishell->path[i]) + my_strlen(cmd) + 2));
        path = my_strcpy(tab[i]);
        path = my_strcat(my_strcat(path, "/"), cmd);
        if (!access(path, X_OK))
            return (path);
    }
    return (NULL);
}