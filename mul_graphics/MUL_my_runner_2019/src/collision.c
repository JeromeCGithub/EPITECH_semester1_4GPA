/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** manage collision
*/

#include <my.h>

void dead_animation(sfRenderWindow *window, game_t *game)
{
    sfTime time;
    sfClock *clock = sfClock_create();
    sfIntRect dead_anim = {0, Y_PLAYER_SIZE * DEAD,
                            X_PLAYER_SIZE, Y_PLAYER_SIZE};

    sfSound_play(game->dead_sound);
    sfSprite_setTextureRect(game->player->player_sprite, dead_anim);
    while (dead_anim.left != X_PLAYER_SIZE * NB_SPRITE_PLAYER[DEAD]) {
        time = sfClock_getElapsedTime(clock);
        if (time.microseconds > 60000) {
            dead_anim.left += X_PLAYER_SIZE;
            sfSprite_setTextureRect(game->player->player_sprite, dead_anim);
            sfClock_restart(clock);
        }
        display_game(game, window);
    }
}

int col_fire(sfRenderWindow *window, obstacle_t *obs,
            sfVector2f position_obs, game_t *game)
{
    sfVector2f position_player = sfSprite_getPosition
        (game->player->player_sprite);

    if (obs->fire == 0)
        return (0);
    if (position_player.x + int_cv(window, 135, 0) >= position_obs.x
        && position_player.x + int_cv(window, 50, 0) <= position_obs.x
        && position_player.y + int_cv(window, 130, 1) >= position_obs.y
        && game->player->current_animation != FALL) {
        return (1);
    }
    return (0);
}

int col_piks(sfRenderWindow *window, obstacle_t *obs,
            sfVector2f position_player, sfVector2f position_obs)
{
    if (obs->fire == 1)
        return (0);
    if (position_player.x + int_cv(window, 135, 0) >= position_obs.x
        && position_player.x + int_cv(window, 50, 0) <= position_obs.x
        && position_player.y + int_cv(window, 130, 1) >= position_obs.y) {
        return (1);
    }
    return (0);
}

void manage_collision(sfRenderWindow *window, game_t *game)
{
    obstacle_t *obs = game->obs;
    sfVector2f position_player = sfSprite_getPosition
        (game->player->player_sprite);
    sfVector2f position_obs;

    while (obs != NULL) {
        position_obs = sfSprite_getPosition(obs->sprite_obs);
        if (col_fire(window, obs, position_obs, game)
            || col_piks(window, obs, position_player, position_obs)) {
            save_score(game->score);
            dead_animation(window, game);
            game_over(window, game);
        } else if (!obs->is_scored && position_player.x >= position_obs.x) {
            game->score += 1;
            obs->is_scored = 1;
        }
        obs = obs->next_obs;
    }
}
