/*
** EPITECH PROJECT, 2019
** lib
** File description:
** load music
*/

#include <my.h>

void destroy_music(sfMusic *music)
{
    sfMusic_stop(music);
    sfMusic_destroy(music);
}

sfMusic *load_music(char const *music_file)
{
    sfMusic *music = sfMusic_createFromFile(music_file);

    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return (music);
}
