/*
** EPITECH PROJECT, 2019
** final_stumper
** File description:
** main final stumper
*/

#include <unistd.h>
#include "include/my.h"

void onsepo(int counter1, int counter2)
{
    my_putstr("[rush1-3] ");
    my_put_nbr(counter1);
    my_putchar(' ');
    my_put_nbr(counter2);
    my_putstr(" || [rush1-4] ");
    my_put_nbr(counter1);
    my_putchar(' ');
    my_put_nbr(counter2);
    my_putstr(" || [rush1-5] ");
    my_put_nbr(counter1);
    my_putchar(' ');
    my_put_nbr(counter2);
    my_putchar('\n');
}

int detect(char *str, int counter1, int counter2)
{
    if (str[0] == 'o')
        return (1);
    if (str[0] == '/' || str[0] == '*')
        return (2);
    if (str[0] == 'A' && str[counter1 - 1] == 'A')
        return (3);
    if (str[(counter1 + 1) * counter2 - counter1 - 1] == 'A' && str[0] == 'A')
        return (4);
    if (str[0] == 'A' && str[(counter1 + 1) * counter2 - 2] == 'A' &&
        str[(counter1 + 1) * counter2 - counter1 - 1] == 'C'
        && str[counter1 - 1] == 'C')
        return (5);
    if ((counter1 == 1 || counter2 == 1) && str[counter1 - 1] == 'B') {
        if (check_b(str, counter1, counter2) == 1){
            onsepo(counter1, counter2);
            return (7);
        }
    }
    return (0);
}

void display(int number_rush, int counter1, int counter2)
{
    my_putstr("[rush1-");
    my_put_nbr(number_rush);
    my_putstr("] ");
    my_put_nbr(counter1);
    my_putchar(' ');
    my_put_nbr(counter2);
    my_putchar('\n');
}

void rush3(char *str)
{
    int counter1 = 0;
    int counter2 = 0;
    int number_rush = 0;

    for (int i = 0 ; str[i] != '\n' ; i++)
        counter1++;
    for (int j = 0 ; str[j] != '\0' ; j++) {
        if (str[j] == '\n')
            counter2++;
    }
    number_rush = detect(str, counter1, counter2);
    if (number_rush == 0) {
        my_putstr("none\n");
        return;
    }
    else if (number_rush != 7)
        display(number_rush, counter1, counter2);
}

int main(void)
{
    char buff[4096];
    int len = 1;
    int offset = 0;

    while ((len = read(0, buff + offset, 4096 - len)) > 0)
        offset = offset + len;
    buff[offset + len] = '\0';
    if (len < 0)
        return (84);
    rush3(buff);
    return (0);
}
