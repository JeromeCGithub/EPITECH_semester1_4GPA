/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** manage map
*/

#include <my.h>

void win(sfRenderWindow *window, game_t *game)
{
    sfClock *clock = sfClock_create();
    sfEvent event;
    sfTime time;
    sfVector2f pos_player = sfSprite_getPosition
        (game->player->player_sprite);

    while (sfRenderWindow_isOpen(window)) {
        time = sfClock_getElapsedTime(clock);
        while (sfRenderWindow_pollEvent(window, &event))
            (event.type == sfEvtClosed) ? sfRenderWindow_close(window) : event;
        manage_player_move(window, game);
        if (time.microseconds > 1000)
            pos_player.x += 10;
        sfSprite_setPosition(game->player->player_sprite, pos_player);
        display_game(game, window);
        if (pos_player.x + 170 > 1920)
            victory_menu(window, game);
    }
}

void new_obs_piks(sfRenderWindow *window, obstacle_t **obs, game_t *game)
{
    sfVector2f position = convert_vector2f(window, 1920, 772);
    sfVector2f scale = convert_vector2f(window, 0.2, 0.2);
    sfIntRect position_rect = {0, 0, 159, 325};
    obstacle_t *new_obs = malloc(sizeof(obstacle_t));

    new_obs->fire = 0;
    new_obs->is_scored = 0;
    new_obs->sprite_obs = sfSprite_create();
    sfSprite_setTexture(new_obs->sprite_obs, game->texture_obs, sfTrue);
    sfSprite_setTextureRect(new_obs->sprite_obs, position_rect);
    sfSprite_setPosition(new_obs->sprite_obs, position);
    sfSprite_scale(new_obs->sprite_obs, scale);
    new_obs->next_obs = *obs;
    *obs = new_obs;
}

void new_obs_fire(sfRenderWindow *window, obstacle_t **obs, game_t *game)
{
    sfVector2f position = convert_vector2f(window, 1920, 670);
    sfVector2f scale = convert_vector2f(window, 0.2, 0.2);
    sfIntRect position_rect = {0, 326, 220, 110};
    obstacle_t *new_obs = malloc(sizeof(obstacle_t));

    new_obs->fire = 1;
    new_obs->is_scored = 0;
    new_obs->clock = sfClock_create();
    new_obs->sprite_obs = sfSprite_create();
    sfSprite_setTexture(new_obs->sprite_obs, game->texture_obs, sfTrue);
    sfSprite_setTextureRect(new_obs->sprite_obs, position_rect);
    sfSprite_setPosition(new_obs->sprite_obs, position);
    sfSprite_scale(new_obs->sprite_obs, scale);
    new_obs->next_obs = *obs;
    *obs = new_obs;
}

void manage_map_infinite(sfRenderWindow *window, game_t *game)
{
    static int nb_piks = 0;
    sfTime time;

    time = sfClock_getElapsedTime(game->map_clock);
    if (sfTime_asSeconds(time) > 1) {
        if (rand() % 100 < 35) {
            new_obs_piks(window, &game->obs, game);
            nb_piks = 0;
        }
        else if (rand() % 100 < 45 && nb_piks > 5) {
            new_obs_fire(window, &game->obs, game);
            nb_piks = 0;
        }
        nb_piks += 1;
        for (int i = 0 ; i < NB_STACK ; i++)
            game->bg->speed[i] -= 0.05;
        sfClock_restart(game->map_clock);
    }
}

void manage_map(sfRenderWindow *window, game_t *game)
{
    sfTime time;

    time = sfClock_getElapsedTime(game->map_clock);
    if (sfTime_asSeconds(time) > 1) {
        if (game->map->map[0] != '\0')
            game->map->map = &game->map->map[1];
        if (game->map->map[0] == '1')
            new_obs_piks(window, &game->obs, game);
        if (game->map->map[0] == '2')
            new_obs_fire(window, &game->obs, game);
        else if (game->map->map[0] == '\0' && game->obs == NULL) {
            save_score(game->score);
            win(window, game);
        }
        sfClock_restart(game->map_clock);
    }
}
