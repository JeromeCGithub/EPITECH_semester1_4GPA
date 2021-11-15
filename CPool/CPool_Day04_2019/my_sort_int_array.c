/*
** EPITECH PROJECT, 2019
** my_sort_int_array
** File description:
** Sort in order
*/

int compa(int *array, int *i, int *j)
{
    int save = 0;
    
    if (array[*j] > array[*i])
    {
        save = array[*i];
        array[*i] = array[*j];
        array[*j] = save;
    }
    return (0);
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int j = 0;

    for (i = 0 ; i < size ; i++)
    {
        for (j = 0 ; j < size ; j++)
        {
            compa(array, &i, &j);
        }
    }
}
