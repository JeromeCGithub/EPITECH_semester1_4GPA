/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** manage bg moove
*/

#include <my.h>

void manage_jump(player_t *player, sfRenderWindow *window)
{
    sfVector2f position = sfSprite_getPosition(player->player_sprite);
    sfTime time = sfClock_getElapsedTime(player->jump_clock);

    if (position.y >= PLAYER_POS_Y)
        return;
    position.y = (-(1.0 / 2.0)) * int_cv(window, 275.0, 1)
        * powf(sfTime_asSeconds(time) * 2.0, 2)
        + int_cv(window, 300.0, 1) * sin(90) * sfTime_asSeconds(time) * 2.0;
    position.y *= -1;
    position.y += int_cv(window, PLAYER_POS_Y, 1) - int_cv(window, 50, 1);
    sfSprite_setPosition(player->player_sprite, position);
}

void animation_correction(player_t *player, sfRenderWindow *window)
{
    sfVector2f pos = convert_vector2f(window, PLAYER_POS_X, PLAYER_POS_Y);

    if (player->current_animation == JUMP)
        manage_jump(player, window);
    else if (player->current_animation == FALL) {
        pos.y += 10;
        sfSprite_setPosition(player->player_sprite, pos);
    }
    else
        sfSprite_setPosition(player->player_sprite, pos);
}

void manage_player_move(sfRenderWindow *window, game_t *game)
{
    sfIntRect text_rect_origin = {0, 0, X_PLAYER_SIZE, Y_PLAYER_SIZE};
    sfIntRect text_rect = sfSprite_getTextureRect(game->player->player_sprite);
    sfTime time;

    animation_correction(game->player, window);
    time = sfClock_getElapsedTime(game->player->player_clock);
    if (time.microseconds > 60000) {
        text_rect.top = PLAYER_POS_Y * game->player->current_animation;
        text_rect.left += X_PLAYER_SIZE;
        if (text_rect.left >= X_PLAYER_SIZE *
            NB_SPRITE_PLAYER[game->player->current_animation]) {
            sfSprite_setTextureRect
                (game->player->player_sprite, text_rect_origin);
            game->player->current_animation = RUN;
        }
        else
            sfSprite_setTextureRect(game->player->player_sprite, text_rect);
        sfClock_restart(game->player->player_clock);
    }
    manage_bird(window, game);
}

void move_rect(obstacle_t **obs)
{
    sfIntRect text_rect_origin = {0, 326, 210, 110};
    sfIntRect text_rect = sfSprite_getTextureRect((*obs)->sprite_obs);
    sfTime time;

    if ((*obs)->fire == 1)
        time = sfClock_getElapsedTime((*obs)->clock);
    if ((*obs)->fire == 1 && time.microseconds >= 80000) {
        text_rect.left += 220;
        if (text_rect.left >= 220 * 5)
            sfSprite_setTextureRect((*obs)->sprite_obs, text_rect_origin);
        else
            sfSprite_setTextureRect((*obs)->sprite_obs, text_rect);
        sfClock_restart((*obs)->clock);
    }
}

void manage_background_moove(game_t *game, sfRenderWindow *window)
{
    sfTime time;
    sfVector2f position;
    sfVector2f to_add;

    for (int i = 0 ; i < NB_STACK ; i++) {
        time = sfClock_getElapsedTime(game->bg->clock[i]);
        if (time.microseconds > 4000) {
            to_add.y = 0;
            to_add.x = game->bg->speed[i];
            sfSprite_move(game->bg->background[i], to_add);
            manage_obs_move(window, game, i, to_add);
            sfClock_restart(game->bg->clock[i]);
        }
        position = sfSprite_getPosition(game->bg->background[i]);
        if (position.x < int_pos_window(window, 1920, 0) * -1) {
            to_add.x = 0;
            sfSprite_setPosition(game->bg->background[i], to_add);
        }
    }
    manage_player_move(window, game);
}
