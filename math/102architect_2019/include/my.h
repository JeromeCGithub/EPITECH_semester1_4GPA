/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** my.h
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void error_handling(char **);
void print_h(char const *);
void parse_args(int, char **);
void display_matrice(float **);
void multiply_matrice(float **, float [3][3]);
void multiply_matrice_pnt(float *, float **);
float **init_matrice(void);
float *init_p(float, float, float);
void reflection(float **, char **);
void rotation(float **, char **);
void scaling(float **, char **);
void translation(float **, char **);
