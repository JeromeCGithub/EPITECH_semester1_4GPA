/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** init background
*/

#include <my.h>

static background_t *set_pos_scale(background_t *bg, sfRenderWindow *window)
{
    sfVector2f pos[NB_STACK] = {convert_vector2f(window, 0, 0),
                                convert_vector2f(window, 0, 0),
                                convert_vector2f(window, 0, 0),
                                convert_vector2f(window, 0, 0),
                                convert_vector2f(window, 0, 0),
                                convert_vector2f(window, 0, 0)};
    sfVector2f scale[NB_STACK] = {convert_vector2f(window, 1, 1),
                                    convert_vector2f(window, 1, 1),
                                    convert_vector2f(window, 1, 1),
                                    convert_vector2f(window, 1, 1),
                                    convert_vector2f(window, 1, 1),
                                    convert_vector2f(window, 1, 1)};

    for (int i = 0 ; i < NB_STACK ; i++)
        sfSprite_setPosition(bg->background[i], pos[i]);
    for (int i = 0 ; i < NB_STACK ; i++)
        sfSprite_setScale(bg->background[i], scale[i]);
    return (bg);
}

static background_t *set_texture(background_t *bg, sfRenderWindow *window)
{
    sfTexture *spritesheet = sfTexture_createFromFile
        ("img/spritesheet_bg.png", NULL);
    sfIntRect positionsheet[NB_STACK] = {{0, POS_SHEET * FOND, 3840, 1080},
                                    {0, POS_SHEET * COLLINE + 50, 3840, 1080},
                                    {0, POS_SHEET * NUAGE, 3840, 1080},
                                    {0, POS_SHEET * ARBRE + 50, 3840, 1080},
                                    {0, POS_SHEET * GATEAU + 50, 3840, 1080},
                                    {0, POS_SHEET * SOL + 50, 3840, 1080}};

    for (int i = 0 ; i < NB_STACK ; i++)
        sfSprite_setTexture(bg->background[i], spritesheet, sfTrue);
    for (int i = 0 ; i < NB_STACK ; i++)
        sfSprite_setTextureRect(bg->background[i], positionsheet[i]);
    return (bg);
}

static background_t *setclock(background_t *bg, sfRenderWindow *window)
{
    for (int i = 0 ; i < NB_STACK ; i++)
        bg->clock[i] = sfClock_create();
    return (bg);
}

background_t *setspeed(background_t *bg, sfRenderWindow *window, int speed)
{
    bg->speed[FOND] = float_cv(window, VITESSE_FOND, 0) * (speed / 10);
    bg->speed[COLLINE] = float_cv(window, VITESSE_COLLINE, 0) * (speed / 10);
    bg->speed[NUAGE] = float_cv(window, VITESSE_NUAGE, 0) * (speed / 10);
    bg->speed[ARBRE] = float_cv(window, VITESSE_ARBRE, 0) * (speed / 10);
    bg->speed[GATEAU] = float_cv(window, VITESSE_GATEAU, 0) * (speed / 10);
    bg->speed[SOL] = float_cv(window, VITESSE_SOL, 0) * (speed / 10);
    bg->speed[PLAYER] = float_cv(window, VITESSE_PLAYER, 0) * (speed / 10);
    return (bg);
}

game_t *init_game(sfRenderWindow *window, map_t *map, int inf)
{
    game_t *game = malloc(sizeof(game_t));

    load_score(window, game);
    game->bird_fly = NULL;
    game->text_bird = sfTexture_createFromFile("img/spritesh_bird.png", NULL);
    game->map = map;
    game->obs = NULL;
    game->texture_obs = sfTexture_createFromFile("img/spriteobs.png", NULL);
    game->map_clock = sfClock_create();
    init_player(window, game);
    game->bg = malloc(sizeof(background_t));
    for (int i = 0 ; i < NB_STACK ; i++)
        game->bg->background[i] = sfSprite_create();
    game->bg = set_texture(game->bg, window);
    game->bg = set_pos_scale(game->bg, window);
    game->bg = setclock(game->bg, window);
    game->bg = setspeed(game->bg, window, (inf) ? 10 : game->map->speed);
    init_sound(game);
    return (game);
}
