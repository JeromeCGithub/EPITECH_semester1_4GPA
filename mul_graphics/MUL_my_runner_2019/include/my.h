/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** my
*/

#ifndef MY_H_

#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <time.h>
#include <math.h>
#include <stddef.h>

typedef struct coord {
    float x;
    float y;
} coord_t;

typedef struct bird {
    sfSprite *bird_sprite;
    sfClock *clock_bird;
    sfClock *clock_speed;
    float speed;
    struct bird *next;
} bird_t;

typedef struct background {
    sfSprite *background[8];
    sfClock *clock[8];
    float speed[8];
} background_t;

typedef struct obstacle {
    sfSprite *sprite_obs;
    sfClock *clock;
    int is_scored;
    int fire;
    struct obstacle *next_obs;
} obstacle_t;

typedef struct player {
    sfSprite *player_sprite;
    sfClock *player_clock;
    sfClock *jump_clock;
    int current_animation;
} player_t;

typedef struct map {
    char *map_name;
    char *map_origin;
    char *map;
    float speed;
    int inf;
} map_t;

typedef struct pause {
    sfText *pause_txt;
    sfText *score_act;
    sfText *score_txt;
    sfText *best_score_txt;
    sfSprite *element[4];
} pause_t;

typedef struct game {
    sfSprite *score_board;
    background_t *bg;
    player_t *player;
    map_t *map;
    sfClock *map_clock;
    obstacle_t *obs;
    obstacle_t *bird;
    sfTexture *texture_obs;
    sfTexture *text_bird;
    int score;
    int inf;
    bird_t *bird_fly;
    sfClock *clock_bird;
    sfMusic *music;
    sfSound *jump_sound;
    sfSoundBuffer *jump_sound_buffer;
    sfSound *dead_sound;
    sfSoundBuffer *sound_buffer;
    sfText *score_txt;
} game_t;

static const int NB_SPRITE_PLAYER[4] = {11, 16, 11, 16};

static const int X_PLAYER_SIZE = 934;
static const int Y_PLAYER_SIZE = 641;

static const float VITESSE_FOND = 0;
static const float VITESSE_COLLINE = -1;
static const float VITESSE_ARBRE = -2.1;
static const float VITESSE_GATEAU = -2.6;
static const float VITESSE_SOL = -3;
static const float VITESSE_NUAGE = -0.3;
static const float VITESSE_PLAYER = 0;

static const int POS_SHEET = 1080;

static const int PLAYER_POS_X = 250;
static const int PLAYER_POS_Y = 660;
static const float PLAYER_SCALE = 0.3;

static const sfVideoMode MODE = {1920, 1080, 32};

enum menu_button {PLAY = 1, QUIT, INF_BUTTON};
enum player_position_sheet {RUN, JUMP, FALL, DEAD};
enum bg_number {FOND, COLLINE, NUAGE, ARBRE, GATEAU, SOL, PLAYER, NB_STACK};

bird_t *delete_bird(bird_t *, int);
int check_env(char **);
void display_score(sfRenderWindow *, pause_t *);
int char_to_nb(char *);
void init_score(pause_t *, sfRenderWindow *, int);
char *find_high_nb(char *);
int my_nblen(int);
void save_score(int);
void load_score(sfRenderWindow *, game_t *);
void manage_bird(sfRenderWindow *, game_t *);
int my_atoi(char const *str);
char *my_strdup(char const *str);
map_t *next_map(char *, game_t *);
void manage_victory_mouse_play(sfRenderWindow *, sfSprite **);
map_t *load_map(char const *, int);
void victory_menu(sfRenderWindow *, game_t *);
void display_game_menu(sfRenderWindow *, game_t *);
void game_over(sfRenderWindow *, game_t *);
void input_souris_two(sfRenderWindow *, map_t *, sfMusic *, sfEvent);
void pause_input_souris(sfRenderWindow *window, sfEvent event, int *is_open);
void manage_pause_mouse_play(sfRenderWindow *window, sfSprite **button);
void pause_menu(sfRenderWindow *window, game_t *game);
void move_rect(obstacle_t **obs);
void manage_obs_move(sfRenderWindow *window, game_t *game,
                    int i, sfVector2f to_add);
void manage_map_infinite(sfRenderWindow *window, game_t *game);
void destroy_game(game_t *game);
void init_player(sfRenderWindow *window, game_t *game);
sfSprite **set_button(sfRenderWindow *window);
void resize(sfRenderWindow *window, game_t *game, sfSprite **menu_button);
float float_cv(sfRenderWindow *window, float nb, int indice);
int int_cv(sfRenderWindow *window, int nb, int indice);
void destroy_bg(background_t *bg);
void destroy_music(sfMusic *music);
void input_souris(sfRenderWindow *window, map_t *map,
                    sfMusic *music, sfEvent event);
void manage_menu_mouse_play(sfRenderWindow *window, sfSprite **button);
game_t *init_menu(sfRenderWindow *window);
void menu_loop(sfRenderWindow *window, map_t *map, int inf);
obstacle_t *delete_node(obstacle_t *obs, int compteur, sfVector2f pos);
void display_game(game_t *game, sfRenderWindow *window);
void manage_player_move(sfRenderWindow *window, game_t *game);
char *my_revstr(char *str);
int my_strlen(char const *str);
void manage_score(sfText *score_txt, int score, sfRenderWindow *window);
void manage_collision(sfRenderWindow *window, game_t *game);
sfText *create_text(char const *police, unsigned int taille,
                    sfVector2f position, char *contenue);
void manage_map(sfRenderWindow *window, game_t *game);
void init_sound(game_t *game);
void manage_input(sfRenderWindow *window, player_t *player,
                    sfEvent *event, game_t *game);
int int_pos_window(sfRenderWindow *window, int nb, int indice);
void manage_background_moove(game_t *game, sfRenderWindow *window);
sfVector2f convert_vector2f(sfRenderWindow *window, float x, float y);
game_t *init_game(sfRenderWindow *window, map_t *map, int inf);
void game_loop(sfRenderWindow *window, map_t *map, sfMusic *music, int inf);
sfMusic *load_music(char const *);
void my_putstr(char const *str);

#endif
