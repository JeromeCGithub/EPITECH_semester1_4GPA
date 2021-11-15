/*
** EPITECH PROJECT, 2019
** calc
** File description:
** calccc
*/

#include <stdlib.h>
#include "include/mycalc.h"

void stackit(stack_t *stack, int number_to_stack)
{
    element_t *new = malloc(sizeof(element_t));

    new->number = number_to_stack;
    new->next = stack->first;
    stack->first = new;
}

int unstack_it(stack_t *stack)
{
    int number_unstacked = 0;
    element_t *element_unstacked = stack->first;

    if (stack != NULL && stack->first != NULL) {
        number_unstacked = element_unstacked->number;
        stack->first = element_unstacked->next;
        free(element_unstacked);
    }
    return (number_unstacked);
}

stack_t *init(void)
{
    stack_t *stack = malloc(sizeof(stack_t));

    return (stack);
}

void jump_to_next_number(int *i, char *expr)
{
    while (expr[*i] <= '9' && expr[*i] >= '0' && expr[*i] != '\0')
        *i = *i + 1;
}

int calc(char *expr)
{
    stack_t *my_stack = init();
    int operand1 = 0;
    int operand2 = 0;
    int result = 0;

    for (int i = 0 ; expr[i] != '\0' ; i++) {
        if (expr[i] <= '9' && expr[i] >= '0') {
            stackit(my_stack, my_getnbr(&expr[i]));
            jump_to_next_number(&i, expr);
        }
        else if (expr[i] == '+' || expr[i] == '-' ||
            expr[i] == '*' || expr[i] == '/' ||
            expr[i] == '%') {
            operand2 = unstack_it(my_stack);
            operand1 = unstack_it(my_stack);
            result = do_op(expr[i], operand1, operand2);
            stackit(my_stack, result);
        }
    }
    return (unstack_it(my_stack));
}
