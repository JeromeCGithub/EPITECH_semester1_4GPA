/*
** EPITECH PROJECT, 2019
** my_print_params
** File description:
** Print argument of the main.
*/

void my_putchar(char c);

int my_putstr11(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    for (int i = 0 ; i < argc ; i++)
    {
            my_putstr11(argv[i]);
            my_putchar('\n');
    }
    return (0);
}
