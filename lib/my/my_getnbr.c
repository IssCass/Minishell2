/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** task05
*/

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;
    int check;
    int num = 1;

    while (str[i] == '+' || str[i] == '-') {
        if (str [i] == '-')
            num *= -1;
        i++;
    }
    while (str[i] <= '9' && str[i] >= '0') {
        check = nb;
        nb = nb * 10 + (str[i] - 48);
        if (nb == 214748364 && str[i + 1] == '8' && num > 0)
            return (0);
        if (nb / 10 != check && nb != -2147483648)
            return (0);
        i++;
    }
    return (nb * num);
}