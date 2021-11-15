/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** obs move
*/

#include <my.h>

void manage_obs_move(sfRenderWindow *window, game_t *game,
                    int i, sfVector2f to_add)
{
    int compteur = 0;
    sfVector2f pos;
    obstacle_t *obs = game->obs;

    if (i == SOL) {
        while (obs != NULL) {
            (obs->fire == 1) ? to_add.x = game->bg->speed[i] - 4 :
                (to_add.x = game->bg->speed[i]);
            move_rect(&obs);
            pos = sfSprite_getPosition(obs->sprite_obs);
            sfSprite_move(obs->sprite_obs, to_add);
            game->obs = delete_node(game->obs, compteur, pos);
            (obs) ? (obs = obs->next_obs) : obs;
            compteur++;
        }
    }
}
