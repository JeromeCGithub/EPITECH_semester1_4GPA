/*
** EPITECH PROJECT, 2019
** tests_my_put_nbr
** File description:
** Testing put_nbr.
*/

int my_put_nbr(int nb);

int main(void)
{
    my_put_nbr(42);
    my_put_nbr(0);
    my_put_nbr(-42);
    my_put_nbr(-2147483648);
    my_put_nbr(2147483647);
    return(0);
}
