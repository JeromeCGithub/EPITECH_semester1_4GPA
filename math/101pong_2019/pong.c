/*
** EPITECH PROJECT, 2019
** 101pong
** File description:
** main.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include/my.h"

void print_it(coord_t velocity, coord_t *ball_t1, coord_t ball_tn, double n)
{
    double norme = 0;
    double degrees = 0;

    norme = sqrt(velocity.x * velocity.x +
                velocity.y * velocity.y + velocity.z * velocity.z);
    if (norme == 0)
        exit(84);
    degrees = ABS(asin(velocity.z / norme) * 180 / M_PI);
    write(1, "The velocity vector of the ball is:\n", 36);
    printf("(%.2f, %.2f, %.2f)\n", velocity.x, velocity.y, velocity.z);
    printf("At time t + %.0f, ball coordinates will be:\n", n);
    printf("(%.2f, %.2f, %.2f)\n", ball_tn.x, ball_tn.y, ball_tn.z);
    if ((ball_t1->z < 0 && ball_tn.z > 0)
        || (ball_t1->z > 0 && ball_tn.z < 0)
        || ball_tn.z == 0) {
        printf("The incidence angle is:\n");
        printf("%.2f degrees\n", degrees);
    }
    else
        printf("The ball won't reach the paddle.\n");
}

void print_h(char const *str)
{
    if (str[0] == '-' && str[1] == 'h' && str[2] == '\0') {
        printf("USAGE\n    ./101pong x0 y0 z0 x1 y1 z1 n\n\n");
        printf("DESCRIPTION\n");
        printf("    x0  ball abscissa at time t - 1\n");
        printf("    y0  ball ordinate at time t - 1\n");
        printf("    z0  ball altitude at time t - 1\n");
        printf("    x1  ball abscissa at time\n");
        printf("    y1  ball ordinate at time\n");
        printf("    z1  ball altitude at time\n");
        printf("    n   time shift\
 (greater than or equal to zero, integer)\n");
        exit(0);
    }
    exit(84);
}

coord_t *init(coord_t *object, char const *x,
              char const *y, char const *z)
{
    object = malloc(sizeof(coord_t));
    object->x = atof(x);
    object->y = atof(y);
    object->z = atof(z);
    return (object);
}

void vector_calc(char **av)
{
    coord_t *ball_t = init(ball_t, av[1], av[2], av[3]);
    coord_t *ball_t1 = init(ball_t1, av[4], av[5], av[6]);
    double n = atof(av[7]);
    coord_t ball_tn;
    coord_t velocity;

    velocity.x = ball_t1->x - ball_t->x;
    velocity.y = ball_t1->y - ball_t->y;
    velocity.z = ball_t1->z - ball_t->z;
    ball_tn.x = velocity.x * n + ball_t1->x;
    ball_tn.y = velocity.y * n + ball_t1->y;
    ball_tn.z = velocity.z * n + ball_t1->z;
    print_it(velocity, ball_t1, ball_tn, n);
    free(ball_t);
    free(ball_t1);
}

void error_cases(int ac, char **av)
{
    int tmp = 0;
    
    if (ac != 2 && ac != 8)
        exit(84);
    if (ac == 2)
        print_h(av[1]);
    for (int i = 1 ; i < 8 ; i++) {
        for (int j = 0 ;  av[i][j] != '\0' ; j++) {
            ((av[i][j] > '9' || av[i][j] < '0')
            && av[i][j] != '-' && av[i][j] != '+'
            && av[i][j] != '.') ? (tmp = 1) : tmp;
        }
    }
    if (av[7][0] == '-' || tmp == 1)
        exit(84);
    for (int i = 0 ; av[7][i] != '\0' ; i++)
        if (av[7][i] == '.')
            exit(84);
}
