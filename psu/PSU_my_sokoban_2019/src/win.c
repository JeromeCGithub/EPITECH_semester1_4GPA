/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** is_win
*/

#include "../include/my.h"
#include <stdlib.h>

void is_dead_case(int i, int j, map_t *maps)
{
    int count = 0;

    if (maps->map[i - 1][j] == '#' || maps->map[i - 1][j] == 'X') {
        if ((maps->map[i][j - 1] == '#' || maps->map[i][j - 1] == 'X')
            || (maps->map[i][j + 1] == '#' || maps->map[i][j + 1] == 'X')) {
            maps->case_dead += 1;
            return;
        }
    }
    if (maps->map[i + 1][j] == '#' || maps->map[i + 1][j] == 'X') {
        if ((maps->map[i][j - 1] == '#' || maps->map[i][j - 1] == 'X')
            || (maps->map[i][j + 1] == '#' || maps->map[i][j + 1] == 'X')) {
            maps->case_dead += 1;
            return;
        }
    }
}

void is_lose(map_t *maps)
{
    maps->case_dead = 0;
    for (int i = 0 ; maps->map[i] != 0 ; i++) {
        for (int j = 0 ; maps->map[i][j] != '\0' ; j++) {
            (maps->map[i][j] == 'X') ? is_dead_case(i, j, maps) : maps->cas;
        }
    }
    if (maps->case_dead == maps->cas) {
        free_all(maps);
        exit(1);
    }
}

void is_win(map_t *maps)
{
    maps->cas = 0;
    maps->cas_k = 0;
    for (int i = 0 ; maps->map[i] != 0 ; i++) {
        for (int j = 0 ; maps->map[i][j] != '\0' ; j++) {
            (maps->map[i][j] == 'X') ? maps->cas += 1 : maps->cas;
            (maps->map[i][j] == 'X'
            && maps->map_originale[i][j] == 'O') ? maps->cas_k++ : maps->cas_k;
        }
    }
    if (maps->cas == maps->cas_k) {
        free_all(maps);
        exit(0);
    }
    else
        is_lose(maps);
}
