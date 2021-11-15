/*
** EPITECH PROJECT, 2019
** mycalc.h
** File description:
** my calc dot h here
*/

typedef struct Element element_t;
struct Element
{
    int number;
    element_t *next;
};

typedef struct stack stack_t;
struct stack
{
    element_t *first;
};

void my_putchar(char c);
void my_put_nbr(int nb);
int do_op(char signe, int nb1, int nb2);
int my_getnbr(char const *str);
