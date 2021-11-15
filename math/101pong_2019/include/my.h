/*
** EPITECH PROJECT, 2019
** 101pong
** File description:
** struct
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

#define ABS(c) (c < 0) ? (c * -1) : c;

typedef struct coord
{
    double x;
    double y;
    double z;
} coord_t;

void print_it(coord_t velocity, coord_t *ball_t1, coord_t ball_tn, double n);
void error_cases(int ac, char **av);
void print_h(char const *str);
void vector_calc(char **av);
