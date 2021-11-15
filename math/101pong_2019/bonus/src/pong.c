/*
** EPITECH PROJECT, 2019
** pong
** File description:
** pong
*/

#include "../include/my.h"

static void move_pad(sfRenderWindow *window, pad_t *pad1,
                     pad_t *pad2, back_t *back)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        (pad1->pos.y > 0) ? (pad1->pos.y -= 20) : (0);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        (pad1->pos.y < HEIGHT - pad1->size.y) ? (pad1->pos.y += 20) : (0);
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        (pad2->pos.y > 0) ? (pad2->pos.y -= 20) : (0);
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        (pad2->pos.y < HEIGHT - pad2->size.y) ? (pad2->pos.y += 20) : (0);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        pause_menu(window, back);
    sfRectangleShape_setPosition(pad1->rect, pad1->pos);
    sfRectangleShape_setPosition(pad2->rect, pad2->pos);
}

static void window_event_pong(sfRenderWindow *window, back_t *back,
                        pad_t *pad1, pad_t *pad2)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(window, &event)) {
        switch (event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(window);
            break;
        case sfEvtKeyPressed:
            move_pad(window, pad1, pad2, back);
            break;
        default:
            break;
        }
    }
}


void move_ball(ball_t *ball, pad_t *pad1, pad_t *pad2)
{
    if ((ball->pos.x - ball->radius < pad1->pos.x
        && ball->pos.x - ball->radius > pad1->pos.x - pad1->size.x
        && ball->pos.y > pad1->pos.y
        && ball->pos.y < pad1->pos.y + pad1->size.y)
        || (ball->pos.x + ball->radius > pad2->pos.x
            && ball->pos.x - ball->radius < pad2->pos.x + pad2->size.x
            && ball->pos.y > pad2->pos.y
            && ball->pos.y < pad2->pos.y + pad2->size.y))
        ball->speed.x *= -1;
    if (ball->pos.y + ball->radius > HEIGHT || ball->pos.y + ball->radius < 0)
        ball->speed.y *= -1;
    ball->pos.x += ball->speed.x;
    ball->pos.y += ball->speed.y;
    sfCircleShape_setPosition(ball->circle, ball->pos);
}

void respawn_ball(sfRenderWindow *window, ball_t *ball,
                  pad_t *pad1, pad_t *pad2)
{
    sfClock *clock = sfClock_create();

    ball->speed.x *= -1;
    ball->pos.x = (float)WIDTH * 0.5 - ball->radius * 0.5;
    ball->pos.y = (float)HEIGHT * 0.5 - ball->radius * 0.5;
    pad1->pos.y = (float)HEIGHT * 0.5 - pad1->size.y * 0.5;
    pad2->pos.y = (float)HEIGHT * 0.5 - pad2->size.y * 0.5;
    sfRectangleShape_setPosition(pad1->rect, pad1->pos);
    sfRectangleShape_setPosition(pad2->rect, pad2->pos);
    sfCircleShape_setPosition(ball->circle, ball->pos);
    sfRenderWindow_drawRectangleShape(window, pad1->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, pad2->rect, NULL);
    sfRenderWindow_drawCircleShape(window, ball->circle, NULL);
    sfRenderWindow_display(window);
    while (sfClock_getElapsedTime(clock).microseconds < 3000000);
    sfClock_destroy(clock);
}

int compteur(ball_t *ball, text_t *text, pad_t *pad1, pad_t *pad2)
{
    move_ball(ball, pad1, pad2);
    if (ball->pos.x + ball->radius < 0) {
        text->str[my_strlen(text->str) - 1]++;
        return (1);
    }
    if (ball->pos.x > WIDTH) {
        text->str[0]++;
        return (1);
    }
    return (0);
}

int no_winner(sfRenderWindow *window, text_t *text, back_t *back)
{
    if (text->str[0] == NB_POINTS + '0') {
        game_over(window, 0, back);
        text->str[0] = '0';
        text->str[my_strlen(text->str) - 1] = '0';
    }
    else if (text->str[my_strlen(text->str) - 1] == NB_POINTS + '0') {
        game_over(window, 2, back);
        text->str[0] = '0';
        text->str[my_strlen(text->str) - 1] = '0';
    }
    sfText_setString(text->sftext, text->str);
    return (1);
}

void pong(sfRenderWindow *window)
{
    back_t *back = create_background("pack/Background.png");
    pad_t *pad_j1 = create_pad(10, (float)HEIGHT * 0.5, PAD_X, PAD_Y);
    pad_t *pad_j2 = create_pad(WIDTH - 20, (float)HEIGHT * 0.5, PAD_X, PAD_Y);
    ball_t *ball = create_ball();
    text_t *text = create_text("0       0");

    while (sfRenderWindow_isOpen(window) && no_winner(window, text, back)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, back->sprite, NULL);
        window_event_pong(window, back, pad_j1, pad_j2);
        compteur(ball, text, pad_j1, pad_j2) ?
            (respawn_ball(window, ball, pad_j1, pad_j2)) : (0);
        sfRenderWindow_drawRectangleShape(window, pad_j1->rect, NULL);
        sfRenderWindow_drawRectangleShape(window, pad_j2->rect, NULL);
        sfRenderWindow_drawCircleShape(window, ball->circle, NULL);
        sfRenderWindow_drawText(window, text->sftext, NULL);
        sfRenderWindow_display(window);
    }
    destroy_ball(ball);
    destroy_background(back);
}
