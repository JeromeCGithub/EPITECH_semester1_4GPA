/*
** EPITECH PROJECT, 2019
** 104intersection
** File description:
** cylinder
*/

#include <my.h>

void cylinder(char **av)
{
    float radius = atof(av[P]);
    racine_t racine;
    coords_t point = {atof(av[XP]), atof(av[YP]), atof(av[ZP])};
    coords_t vector = {atof(av[XV]), atof(av[YV]), atof(av[ZV])};
    quadratic_t equation;

    equation.a = pow(vector.x, 2) + pow(vector.y, 2);
    equation.b = 2 * (vector.x * point.x + vector.y * point.y);
    equation.c = (pow(point.x, 2) + pow(point.y, 2)) - pow(radius, 2);
    equation.delta = find_det(equation.a, equation.b, equation.c);
    printf("Cylinder of radius %.0f\n", radius);
    display_delta(point, vector, equation);    
}
