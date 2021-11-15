/*
** EPITECH PROJECT, 2019
** ray_casting
** File description:
** dist
*/

#include <my.h>

float dist(sfVector2f p1, sfVector2f p2)
{
    return (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));
}
