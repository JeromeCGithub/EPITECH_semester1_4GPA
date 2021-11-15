/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** my h
*/

#include "struct.h"

char **complete_tab(int collumn, char **tab, char *buff, int line);
map_t *moove(int key, map_t *maps);
void game(map_t *maps, char *buff);
void free_all(map_t *maps);
int find_coll(char *buff);
void manage_size(map_t *maps, char *buff);
int my_strlen(char *str);
void display_map(map_t *maps);
void check_map(char *buff);
void is_win(map_t *maps);
char *read_it(char const *str);
char **store_map(char *buff);
void print_h(char **av);
void my_putstr(char const *str);
char **moove_case(char **ma, coord_t po, int mou);
int check_moove(char **map, coord_t pos, int mouvement);
int check_moove2(char **map, coord_t pos, int mouvement);
char **move_right(char **map, char **map_org);
char **move_left(char **map, char **map_org);
char **move_up(char **map, char **map_org);
char **move_down(char **map, char **map_org);
