/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** my_texture_destroy
*/

#include "../include/my.h"

void my_texture_destroy(int i, sfTexture **texture)
{
    for (i--; i >= 0; i--)
        sfTexture_destroy(texture[i]);
    free(texture);
}
