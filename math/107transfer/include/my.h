/*
** EPITECH PROJECT, 2020
** 107transfer
** File description:
** my dot h
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct rational_func_s {
    double *num;
    int nb_num;
    double *den;
    int nb_den;
    double result;
} rational_func_t;

int my_engine(int, char **);
int help(char **);
