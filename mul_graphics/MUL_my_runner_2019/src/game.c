/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** game loop
*/

#include <my.h>

void display_game(game_t *game, sfRenderWindow *window)
{
    bird_t *the_bird = game->bird_fly;
    obstacle_t *obs = game->obs;

    sfRenderWindow_clear(window, sfWhite);
    for (int i = 0 ; i < NB_STACK ; i++)
        sfRenderWindow_drawSprite(window, game->bg->background[i], NULL);
    while (obs) {
        sfRenderWindow_drawSprite(window, obs->sprite_obs, NULL);
        obs = obs->next_obs;
    }
    while (the_bird) {
        sfRenderWindow_drawSprite(window, the_bird->bird_sprite, NULL);
        the_bird = the_bird->next;
    }
    sfRenderWindow_drawSprite(window, game->player->player_sprite, NULL);
    sfRenderWindow_drawSprite(window, game->score_board, NULL);
    sfRenderWindow_drawText(window, game->score_txt, NULL);
    sfRenderWindow_display(window);
}

void destroy_bg(background_t *bg)
{
    for (int i = 0 ; i < NB_STACK ; i++)
        sfSprite_destroy(bg->background[i]);
    for (int i = 0 ; i < NB_STACK ; i++)
        sfClock_destroy(bg->clock[i]);
}

void game_loop(sfRenderWindow *window, map_t *map, sfMusic *music, int inf)
{
    game_t *game = init_game(window, map, inf);
    sfEvent event;

    game->map->map_origin = game->map->map;
    game->music = music;
    game->inf = inf;
    sfMusic_play(music);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            (event.type == sfEvtClosed) ? sfRenderWindow_close(window) : event;
            manage_input(window, game->player, &event, game);
        }
        manage_background_moove(game, window);
        (inf) ? manage_map_infinite(window, game) : manage_map(window, game);
        manage_collision(window, game);
        manage_score(game->score_txt, game->score, window);
        display_game(game, window);
    }
    destroy_game(game);
}
