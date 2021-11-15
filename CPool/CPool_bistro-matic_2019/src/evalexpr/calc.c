/*
** EPITECH PROJECT, 2019
** calc
** File description:
** calccc
*/

#include <stdlib.h>
#include "../../include/mycalc.h"
#include "../../include/my.h"

void stackit(stack_t *stack, char *number_to_stack)
{
    element_t *new = malloc(sizeof(element_t));
    char *element = malloc(sizeof(char *) * my_nblen(number_to_stack));

    test_malloc(new);
    test_malloc(element);
    element = my_strncat(element, number_to_stack, my_nblen(number_to_stack));
    new->number = element;
    new->next = stack->first;
    stack->first = new;
}

char *unstack_it(stack_t *stack)
{
    element_t *element_unstacked = stack->first;
    char *number_unstacked;

    if (element_unstacked == NULL)
        return ("0");
    number_unstacked = malloc(sizeof(char *) *
                                my_strlen(element_unstacked->number));
    test_malloc(number_unstacked);
    if (stack != NULL && stack->first != NULL) {
        number_unstacked = element_unstacked->number;
        stack->first = element_unstacked->next;
        free(element_unstacked);
    }
    return (number_unstacked);
}

void jump_to_next_number(int *i, char *expr, stack_t *my_stack)
{
    stackit(my_stack, &expr[*i]);
    while (expr[*i] <= '9' && expr[*i] >= '0' && expr[*i] != '\0')
        *i = *i + 1;
}

char *calc(char const *expr1)
{
    stack_t *my_stack = malloc(sizeof(stack_t));
    char *operand1;
    char *operand2;
    char *result = 0;
    char *expr = my_strdup(expr1);

    test_malloc(my_stack);
    for (int i = 0 ; expr[i] != '\0' ; i++) {
        if (expr[i] <= '9' && expr[i] >= '0')
            jump_to_next_number(&i, expr, my_stack);
        else if (expr[i] == '+' || expr[i] == '-' ||
            expr[i] == '*' || expr[i] == '/' || expr[i] == '%') {
            operand2 = unstack_it(my_stack);
            operand1 = unstack_it(my_stack);
            result = do_op(expr[i], operand1, operand2);
            stackit(my_stack, result);
        }
    }
    return (unstack_it(my_stack));
}
