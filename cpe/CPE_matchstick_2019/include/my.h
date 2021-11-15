/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** my dot h
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct game {
    int line;
    int matchs;
} game_t;

static const int READ_SIZE = 1024;

void ia_worst(int *, int *, game_t *);
void write_formalities(char *, char *);
void print_board(int *, int *, int);
int *find_number_of_match(int);
int matchstick(int, char **);
void impaire_coup(int *, game_t *, int *);
void paire_coup(int *, game_t *, int *);
int find_nb_one_all(int *, int);
int is_balanced(int *, int);
int find_line(int *, int, int);
int end_of_game(int *, int);
int is_win_player(int *, int);
int is_win_ia(int *, int);
int my_ia(int *, game_t *);
int player_turn(int *, int, int);
int is_error_match(int *, char *, int, int);
int is_error_line(char *, int, int, int *);
int my_atoi(char const *);
char *get_next_line(int);
int my_put_nbr(int);
void my_putchar(char);
