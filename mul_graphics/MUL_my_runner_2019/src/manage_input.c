/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** manage input
*/

#include <my.h>

void manage_input(sfRenderWindow *window, player_t *player,
                    sfEvent *event, game_t *game)
{
    sfIntRect jump_rect =
        {X_PLAYER_SIZE * JUMP, 0, X_PLAYER_SIZE, Y_PLAYER_SIZE};
    sfIntRect fall_rect =
        {X_PLAYER_SIZE * FALL, 0, X_PLAYER_SIZE, Y_PLAYER_SIZE};

    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (player->current_animation != RUN)
            return;
        sfSprite_setTextureRect(player->player_sprite, jump_rect);
        player->current_animation = JUMP;
        sfSound_play(game->jump_sound);
        sfClock_restart(player->jump_clock);
    }
    else if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (player->current_animation != RUN)
            return;
        sfSprite_setTextureRect(player->player_sprite, fall_rect);
        player->current_animation = FALL;
    }
    (sfKeyboard_isKeyPressed(sfKeyEscape)) ? pause_menu(window, game) : game;
}
