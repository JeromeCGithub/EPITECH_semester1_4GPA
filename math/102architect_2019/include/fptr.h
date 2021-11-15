/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** fptr
*/

#include "my.h"

typedef void (*fpt)(float **, char **);
fpt fptr[9] = {
    &rotation,
    &reflection,
    &translation,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    &scaling,
};
