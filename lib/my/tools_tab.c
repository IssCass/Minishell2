/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "my.h"
#include <stdlib.h>

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
}

void print_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        my_printf("%s\n", tab[i]);
}