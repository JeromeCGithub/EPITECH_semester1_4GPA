/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** my.h
*/

#include <math.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>

enum params {NAME, OPT, A0, A1, A2, A3, A4, N};

static const char FILE_HELP[] = "help";

void error_handling(int, char **);
void newton(char **);
void bisection(char **);
void secante(char **);
void help(char const *);
int my_strcmp(char const *, char const *);
double derive(char **, double);
double calc_result(char **, double);
