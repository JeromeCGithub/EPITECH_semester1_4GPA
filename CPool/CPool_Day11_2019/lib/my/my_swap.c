/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** A function which swap 2 integer
*/

void my_swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
