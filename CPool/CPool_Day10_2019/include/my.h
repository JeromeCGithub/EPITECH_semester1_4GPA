/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** Define my lib.
*/

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char const *str);
int my_show_word_array(char * const *tab);
int is_character(char const *str, int j);
int is_negative(char const *str, int *j, long int *a);
int puissanc(int len);
int count_digids(long int nb);
void my_putchar1(int nb);
int puissancee(int puissance);
int compa(int *array, int *i, int *j);
char *my_strlowcase2(char *str);
int is_complete_string(char *str, char const *to_find, int i, int *ptr);
int count_number_word(char *new_str);
char **input_this(char const *str, char **array, int number_of_word);
char *remplace_character(char const *str);
