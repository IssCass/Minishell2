/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** my_put_nbr
*/

char my_putchar(char c);

int my_put_unsigned(unsigned int nb)
{
    unsigned int mod;

    if (nb >= 0)
    {
        if (nb >= 10){
            mod = (nb % 10);
            nb = (nb - mod) / 10;
            my_put_unsigned(nb);
            my_putchar(48 + mod);
        }
        else
            my_putchar(48 + nb % 10);
    }
}