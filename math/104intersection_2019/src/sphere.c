/*
** EPITECH PROJECT, 2019
** 104intersections
** File description:
** sphere
*/

#include <my.h>

void sphere(char **av)
{
    float radius = atof(av[P]);
    racine_t racine;
    coords_t point = {atof(av[XP]), atof(av[YP]), atof(av[ZP])};
    coords_t vector = {atof(av[XV]), atof(av[YV]), atof(av[ZV])};
    quadratic_t equation;

    equation.a = pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2);
    equation.b = 2 * (point.x * vector.x + point.y * vector.y + point.z * vector.z);
    equation.c = (pow(point.x, 2) + pow(point.y, 2) + pow(point.z, 2)) - pow(radius, 2);
    equation.delta = find_det(equation.a, equation.b, equation.c);
    printf("Sphere of radius %.0f\n", radius);
    display_delta(point, vector, equation);
}
