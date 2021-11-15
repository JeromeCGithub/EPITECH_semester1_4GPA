/*
** EPITECH PROJECT, 2019
** my sokoban bonus
** File description:
** main
*/

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, Sokoban, sfResize | sfClose, NULL);
    if (!window)
        return (84);
    game_loop(window);
    sfRenderWindow_destroy(window);
    return (0);
}
