/*
** EPITECH PROJECT, 2019
** swap_elem.c
** File description:
** swap 2 elems of an array
*/

void swap_elem(int *array, int index1, int index2)
{
    int tamp;

    tamp = array[index1];
    array[index1] = array[index2];
    array[index2] = tamp;
}