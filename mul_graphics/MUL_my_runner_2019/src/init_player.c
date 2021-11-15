/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** init player
*/

#include <my.h>

void init_sound(game_t *game)
{
    game->jump_sound_buffer = sfSoundBuffer_createFromFile("music/saut.ogg");
    game->jump_sound = sfSound_create();
    sfSound_setBuffer(game->jump_sound, game->jump_sound_buffer);
    sfSound_setVolume(game->jump_sound, 50);
    game->sound_buffer = sfSoundBuffer_createFromFile("music/mort.ogg");
    game->dead_sound = sfSound_create();
    sfSound_setBuffer(game->dead_sound, game->sound_buffer);
    sfSound_setVolume(game->dead_sound, 50);
}

void init_player(sfRenderWindow *window, game_t *game)
{
    sfVector2f scale_player = convert_vector2f
        (window, PLAYER_SCALE, PLAYER_SCALE);
    sfVector2f position_player = convert_vector2f
        (window, PLAYER_POS_X, PLAYER_POS_Y);
    sfIntRect position = {0, 0, X_PLAYER_SIZE, Y_PLAYER_SIZE};
    sfTexture *texture_player = sfTexture_createFromFile
        ("img/spritechar.png", NULL);

    game->player = malloc(sizeof(player_t));
    game->player->current_animation = RUN;
    game->player->player_sprite = sfSprite_create();
    game->player->player_clock = sfClock_create();
    game->player->jump_clock = sfClock_create();
    sfSprite_setTexture(game->player->player_sprite, texture_player, sfTrue);
    sfSprite_setTextureRect(game->player->player_sprite, position);
    sfSprite_scale(game->player->player_sprite, scale_player);
    sfSprite_setPosition(game->player->player_sprite, position_player);
}
