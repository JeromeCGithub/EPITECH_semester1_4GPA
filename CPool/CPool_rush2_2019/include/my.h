/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** Define my lib.
*/

int is_error(int ac, char **av);
int en(char **av);
int ge(char **av);
int fr(char **av);
int sp(char **av);
void my_putstr(char const *str);
int my_strlen(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
char *my_strlowcase(char *str);
char *my_strupcase(char *str);
void print_en(void);
void print_fr(void);
void print_ge(void);
void print_sp(void);
void compare_language(int av_let, int av_en, int av_fr, int av_ge, int av_sp);
