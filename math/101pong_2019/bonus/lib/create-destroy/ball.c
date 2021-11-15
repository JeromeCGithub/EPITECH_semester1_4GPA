/*
** EPITECH PROJECT, 2019
** pong
** File description:
** create_ball
*/

#include "../../include/my.h"

ball_t *create_ball(void)
{
    ball_t *ball = malloc(sizeof(ball_t));

    ball->radius = 15;
    ball->circle = sfCircleShape_create();
    ball->pos.x = (float)WIDTH * 0.5 - ball->radius * 0.5;
    ball->pos.y = (float)HEIGHT * 0.5 - ball->radius * 0.5;
    ball->speed.x = 0.3;
    ball->speed.y = 0.3;
    sfCircleShape_setRadius(ball->circle, ball->radius);
    sfCircleShape_setFillColor(ball->circle, sfWhite);
    sfCircleShape_setPosition(ball->circle, ball->pos);
    return (ball);
}

void destroy_ball(ball_t *ball)
{
    sfCircleShape_destroy(ball->circle);
    free(ball);
}
