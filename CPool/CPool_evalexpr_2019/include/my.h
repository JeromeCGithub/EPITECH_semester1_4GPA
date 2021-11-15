/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** prototypes of the functions
*/

void my_putchar(char c);
void my_put_nbr(int nb);
int my_getnbr(char const *str);
int my_strlen(char const *str);
int do_op(char signe, int nb1, int nb2);
int is_operand(char c);
int is_function(char c);
int op_precedence(char first_stack, char token);
int calc(char *expr);
char *to_npi(char const *str);
char *add_operand(char *op_stack, char const *str, int *j, char *output);
int len_op_stack(char const *str);
int len_output(char const *str);
char *my_memset(char *str, int len);
