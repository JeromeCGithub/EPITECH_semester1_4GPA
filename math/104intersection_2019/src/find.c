/*
** EPITECH PROJECT, 2019
** 104architecht
** File description:
** find
*/

#include <my.h>

float find_det(float a, float b, float c)
{
    float delta = 0;

    delta = pow(b, 2) - 4 * a * c;
    return (delta);
}

racine_t find_racines(float delta, float a, float b)
{
    racine_t racine;

    if (delta) {
        racine.x1 = (-b - sqrt(delta)) / (2 * a);
        racine.x2 = (-b + sqrt(delta)) / (2 * a);
    } else
        racine.x1 = -b / (2 * a);
    return (racine);
}

coords_t find_result(float t, coords_t point, coords_t vector)
{
    coords_t result;

    result.x = point.x + t * vector.x;
    result.y = point.y + t * vector.y;
    result.z = point.z + t * vector.z;
    return (result);
}
