/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** manage brid
*/

#include <my.h>

void new_bird(sfRenderWindow *window, bird_t **bird_fly, game_t *game)
{
    bird_t *new_bird = malloc(sizeof(bird_t));
    sfVector2f position = convert_vector2f(window, -354, rand() % 700);
    int scaling = rand() % 10 + 2;
    sfVector2f scale = convert_vector2f
        (window, (float)scaling / 100, (float)scaling / 100);
    sfIntRect position_rect = {0, 0, 1180, 840};

    new_bird->clock_speed = sfClock_create();
    new_bird->speed = rand() % 4 + 1;
    new_bird->clock_bird = sfClock_create();
    new_bird->bird_sprite = sfSprite_create();
    sfSprite_setTexture(new_bird->bird_sprite, game->text_bird, sfTrue);
    sfSprite_setTextureRect(new_bird->bird_sprite, position_rect);
    sfSprite_setPosition(new_bird->bird_sprite, position);
    sfSprite_scale(new_bird->bird_sprite, scale);
    new_bird->next = *bird_fly;
    *bird_fly = new_bird;
}

void manage_bird_rect(bird_t *bird_fly)
{
    sfIntRect text_rect;
    sfTime time;
    bird_t *the_bird = bird_fly;

    while (the_bird) {
        text_rect = sfSprite_getTextureRect(bird_fly->bird_sprite);
        time = sfClock_getElapsedTime(the_bird->clock_bird);
        if (time.microseconds > 80000) {
            text_rect.left += 1180;
            (text_rect.left >= 9440) ? text_rect.left = 0 : text_rect.left;
            sfSprite_setTextureRect(the_bird->bird_sprite, text_rect);
            sfClock_restart(the_bird->clock_bird);
        }
        the_bird = the_bird->next;
    }
}

void manage_bird_movement(bird_t *bird_fly)
{
    sfTime time;
    sfVector2f to_add;
    bird_t *the_bird = bird_fly;

    while (the_bird) {
        to_add.x = the_bird->speed;
        to_add.y = 0;
        time = sfClock_getElapsedTime(the_bird->clock_speed);
        if (time.microseconds > 10000)
            sfSprite_move(the_bird->bird_sprite, to_add);
        the_bird = the_bird->next;
    }
}

void check_coll(game_t *game)
{
    sfVector2f scale;
    sfVector2f position;
    sfVector2f pos_player = sfSprite_getPosition(game->player->player_sprite);
    bird_t *the_bird = game->bird_fly;
    int compteur;

    while (the_bird) {
        scale = sfSprite_getScale(the_bird->bird_sprite);
        position = sfSprite_getPosition(the_bird->bird_sprite);
        if (pos_player.x + 70 >= position.x
            && pos_player.x + 70 <= position.x + (1000 * scale.x)
            && pos_player.y <= position.y + (840 * scale.y)) {
            game->bird_fly = delete_bird(game->bird_fly, compteur);
            (rand() % 100 > 50 && game->score > 1)
                ? game->score -= 2 : (game->score += 3);
        }
        compteur++;
        the_bird = the_bird->next;
    }
}

void manage_bird(sfRenderWindow *window, game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clock_bird);
    int random = rand() % 100;

    if (random < 1 && time.microseconds >= 1000000) {
        new_bird(window, &game->bird_fly, game);
        sfClock_restart(game->clock_bird);
    }
    manage_bird_rect(game->bird_fly);
    manage_bird_movement(game->bird_fly);
    check_coll(game);
}
