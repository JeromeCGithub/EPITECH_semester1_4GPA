/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** destroy all of them
*/

#include <my.h>

void destroy_game(game_t *game)
{
    sfSound_stop(game->dead_sound);
    sfSound_stop(game->jump_sound);
    sfSound_destroy(game->dead_sound);
    sfSound_destroy(game->jump_sound);
    sfSoundBuffer_destroy(game->sound_buffer);
    sfSoundBuffer_destroy(game->jump_sound_buffer);
    destroy_bg(game->bg);
    sfClock_destroy(game->map_clock);
    sfTexture_destroy(game->texture_obs);
    sfText_destroy(game->score_txt);
}
