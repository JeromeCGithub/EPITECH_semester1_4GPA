/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** prototypes of the functions
*/

#include <stdlib.h>
#define ATN(c) (c - '0')
#define NTA(c) (c + '0')
#define MAX_LEN(nb1, nb2) (((nb1 - nb2) > 0) ? (nb1) : (nb2))

int test_base10(char const *base_nb);
char convert_char(char c, char const *base_nb, char const *base_op);
char *clean_str(char const *str, char const *base_nb, char const *base_op);
char *my_nbtostr(int nb);
char *my_strndog(char const *str1, char const *str2, int n);
char *my_strcat(char const *str1, char const *str2);
char *reconvert(char const *result_10,
                char const *base_nb, char const *base_op);
char *convert_to10(char const *calcul, char const *base_from);
char *signe_subinf(char *result, int signe);
char *subinf_loop(char const *nbr1, char const *nbr2, int signe);
char *addinf_loop(char const *nbr1, char const *nbr2, int signe);
int is_inbase(char const c, char const *base, char const *ops);
int is_operand2(char const c, char const *ops);
void unknow_digit(char const *str, char const *ops, char const *base);
int verif_op(char const *str);
int verif_base(char const *base, char const *op);
int verif_expr(char const *str, char const *op_base);
int verif_string(char const *str);
char *addinf_loop(char const *nbr1, char const *nbr2, int signe);
int fill_neg(char *result, char *nb, int i, int retenue);
void print_h(int ac, char **av);
void my_putstr2(char const *str);
void test_malloc(void const *ptr);
void synt_error(char const *str);
char *string_traitement(char const *str);
char *my_strndup(char const *str, int n);
char *modinf(char const *nb1, char const *nb2);
char *divinf(char const *nb1, char const *nb2);
char *mutinf(char const *nb1, char const *nb2);
char *my_strdup(char const *str);
int my_nbcmp(char const *nb1, char const *nb2);
char *init(char const *nb1, char const *nb2, char signe);
int my_strlen_pimped(char *str);
int my_nblen(char *src);
char *my_strncat(char *dest, char *src, int nb);
char *addinf(char const *nb1, char const *nb2);
char *subinf(char const *nb1, char const *nb2);
char *my_revstr(char *str);
void my_putstr(char const *str);
void my_putchar(char c);
void my_put_nbr(int nb);
int my_getnbr(char const *str);
int my_strlen(char const *str);
char *do_op(char signe, char const *nb1, char const *nb2);
int is_operand(char c);
int is_function(char c);
int op_precedence(char first_stack, char token);
char *calc(char const *expr1);
char *to_npi(char const *str);
char *add_operand(char *op_stack, char const *str, int *j, char *output);
int len_op_stack(char const *str);
int len_output(char const *str);
char *my_memset(char *str, int len, char c);
char *add0(char const *str, char *output, int *j);
