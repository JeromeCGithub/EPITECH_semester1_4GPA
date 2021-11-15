/*
** EPITECH PROJECT, 2019
** my_sort_params
** File description:
** Sort params in order ascii.
*/

void my_putchar(char c);

int my_putstr(char const *str);

int my_strcmp(char const *s1, char const *s2);

int cmpp(char **argv, int i, int j)
{
    char *ptr;

    if (my_strcmp(argv[j], argv[i]) == 1)
    {
        ptr = argv[i];
        argv[i] = argv[j];
        argv[j] = ptr;
    }
}

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    char a = 0;

    for (i = 0 ; i < argc ; i++)
    {
        for (j = 0 ; j < argc ; j++)
        {
            cmpp(argv, i, j);
        }
    }
    for (int l = 0 ; l < argc ; l++)
    {
        my_putstr(argv[l]);
        my_putchar('\n');
    }
    return (0);
}
