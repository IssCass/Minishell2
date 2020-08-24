/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/

#include "minishell2.h"

int errors(int ac)
{
    if (ac != 1)
        return (84);
    return (0);
}