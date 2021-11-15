/*
** EPITECH PROJECT, 2019
** pong
** File description:
** structures
*/

#include "includes.h"

typedef struct ball {
    sfCircleShape *circle;
    float radius;
    sfVector2f pos;
    sfVector2f speed;
} ball_t;

typedef struct pad {
    sfRectangleShape *rect;
    sfVector2f pos;
    sfVector2f size;
    int pnts;
} pad_t;

typedef struct text {
    sfText *sftext;
    char *str;
    sfFont *font;
    sfVector2f pos;
    size_t size;
} text_t;

typedef struct back {
    sfSprite *sprite;
    sfTexture *texture;
} back_t;
