/*
** EPITECH PROJECT, 2019
** 104intersection
** File description:
** my.h
*/

#pragma once

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct quadratic {
    float a;
    float b;
    float c;
    float delta;
} quadratic_t;

typedef struct coords {
    float x;
    float y;
    float z;
} coords_t;

typedef struct racine {
    float x1;
    float x2;
} racine_t;

static const char FILE_HELP[] = "help";

enum {OPT = 1, XP, YP, ZP, XV, YV, ZV, P};

void error_handling(int ac, char **av);
void help(char const *);
int my_strcmp(char const *, char const *);
void sphere(char **);
void display_delta(coords_t, coords_t, quadratic_t);
coords_t find_result(float, coords_t, coords_t);
racine_t find_racines(float, float, float);
void cylinder(char **);
void cone(char **);
float find_det(float, float, float);
