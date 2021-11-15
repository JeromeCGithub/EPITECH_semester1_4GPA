/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include <stdio.h>
#include <math.h>

int main(int ac, char **av)
{
    float a = 0;
    float i = 0;
    
    for (; a < 40 * 180 / M_PI; i++, a += 0.01);
    printf("%.2f\n", (40 * 180 / M_PI));
}
