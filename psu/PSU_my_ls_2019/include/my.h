/*
** EPITECH PROJECT, 2020
** my ls
** File description:
** include
*/

#include <grp.h>
#include <time.h>
#include <pwd.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct content_list {
    char *path;
    struct dirent *content;
    struct content_list *next;
} content_list_t;

enum flags_name {L_FLAG = 1, LITTLE_R_FLAG,
                T_FLAG = 8, BIG_R_FLAG = 4, D_FLAG = 16};

char *my_strlowcase(char *);
char *my_strdup(char const *);
void compare_time(content_list_t **, int *);
void print_total(content_list_t *);
content_list_t *sort_list_alph(content_list_t *);
int is_existing(DIR *, char *);
void display_line(struct stat, int);
void display_readlink(content_list_t *);
void check_flag(size_t *, char *);
int list_size(content_list_t *);
void insert_new(content_list_t *, content_list_t **);
content_list_t *sort_list_t_flag(content_list_t *);
char **pre_sort(int, char **);
int my_strcmp(char const *, char const *);
void manage_big_r_print(char *, size_t);
void my_ls(int ac, char **av, int indice);
void print_time(char *);
void display_owner_user(struct stat);
char *my_strcat(char *, char *);
int my_put_nbr(int);
void display_perm(struct stat);
void display_it(struct dirent *);
void display_ll(content_list_t *, size_t const);
void insert(content_list_t **list, struct dirent *content, char *);
size_t take_flag(char **av);
int my_strlen(char const *);
void my_putstr(char const *);
void listing(char *, size_t const flag);
