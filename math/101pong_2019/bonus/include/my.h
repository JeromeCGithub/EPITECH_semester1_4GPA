/*
** Epitech PROJECT, 2019
** pong
** File description:
** my.h
*/

#include "struct.h"
#include "macros.h"

void main_screen(sfRenderWindow *);
sfTexture **my_texture_create(int, char const *);
void my_texture_destroy(int, sfTexture **);
char *my_strdup(char const *);
int my_strlen(char const *);
void pong(sfRenderWindow *);
void pause_menu(sfRenderWindow *, back_t *);
void game_over(sfRenderWindow *, int, back_t *);
ball_t *create_ball(void);
void destroy_ball(ball_t *);
pad_t *create_pad(float, float, float, float);
void destroy_pad(pad_t *);
back_t *create_background(char const *);
void destroy_background(back_t *);
text_t *create_text(char const *);
void destroy_text(text_t *);
