/*
** EPITECH PROJECT, 2019
** 104intersection
** File description:
** display_delta
*/

#include <my.h>

static void display_basics(coords_t point, coords_t vector)
{
    printf("Line passing through the point ");
    printf("(%.0f, %.0f, %.0f) ", point.x, point.y, point.z);
    printf("and parallel to the vector ");
    printf("(%.0f, %.0f, %.0f)\n", vector.x, vector.y, vector.z);
}

void display_delta(coords_t point, coords_t vector, quadratic_t equation)
{
    coords_t result;
    racine_t racine;

    display_basics(point, vector);
    if (!equation.a) {
        printf("There is an infinite number of intersection points.\n");
        return;
    }
    if (equation.delta < 0)
        printf("No intersection point.\n");
    else if (!equation.delta) {
        printf("1 intersection point:\n");
        racine = find_racines(equation.delta, equation.a, equation.b);
        result = find_result(racine.x1, point, vector);
        printf("(%.3f, %.3f, %.3f)\n", result.x, result.y, result.z);
    } else {
        printf("2 intersection points:\n");
        racine = find_racines(equation.delta, equation.a, equation.b);
        result = find_result(racine.x2, point, vector);
        printf("(%.3f, %.3f, %.3f)\n", result.x, result.y, result.z);
        result = find_result(racine.x1, point, vector);
        printf("(%.3f, %.3f, %.3f)\n", result.x, result.y, result.z);
    }
}
