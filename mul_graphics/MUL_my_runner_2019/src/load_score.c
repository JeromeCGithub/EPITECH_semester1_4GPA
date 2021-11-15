/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** load score
*/

#include <my.h>

void load_score(sfRenderWindow *window, game_t *game)
{
    sfVector2f position = convert_vector2f(window, 792.75, 10);
    sfVector2f scale = convert_vector2f(window, 0.3, 0.3);
    sfTexture *text_board = sfTexture_createFromFile("img/SCORE.png", NULL);

    game->clock_bird = sfClock_create();
    game->score = 0;
    game->score_txt = create_text("police/arial.ttf", 100,
                                convert_vector2f(window, 926, 115), "0");
    game->score_board = sfSprite_create();
    sfSprite_setTexture(game->score_board, text_board, sfTrue);
    sfSprite_setPosition(game->score_board, position);
    sfSprite_scale(game->score_board, scale);
}
