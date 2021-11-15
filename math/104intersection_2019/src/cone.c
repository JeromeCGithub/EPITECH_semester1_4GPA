/*
** EPITECH PROJECT, 2019
** 104intersection
** File description:
** cone
*/

#include <my.h>

void cone(char **av)
{
    float angle = atof(av[P]);
    racine_t racine;
    coords_t point = {atof(av[XP]), atof(av[YP]), atof(av[ZP])};
    coords_t vector = {atof(av[XV]), atof(av[YV]), atof(av[ZV])};
    quadratic_t equation;

    printf("Cone with a %.0f degree angle\n", angle);
    angle = angle * M_PI / 180;
    equation.a = pow(vector.x, 2) + pow(vector.y, 2) - pow(vector.z, 2) * pow(tan(angle), 2);
    equation.b = 2 * (vector.x * point.x + vector.y * point.y - vector.z * point.z * pow(tan(angle), 2));
    equation.c = pow(point.x, 2) + pow(point.y, 2) - pow(point.z, 2) * pow(tan(angle), 2);
    equation.delta = find_det(equation.a, equation.b, equation.c);
    display_delta(point, vector, equation);
}
