/*
** EPITECH PROJECT, 2019
** bonus
** File description:
** my.h
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct ray {
    float angle;
    sfColor color;
    sfVector2f pos;
    sfVector2f dir;
    sfVertexArray *vertex;
    struct ray *next;
} ray_t;

typedef struct wall {
    sfColor color;
    sfVector2f start;
    sfVector2f end;
    sfVertexArray *vertex;
    struct wall *next;
} wall_t;

typedef struct pnt {
    sfColor color;
    sfVector2f pos;
    sfCircleShape *cir;
    struct pnt *next;
} pnt_t;

static const int ANGLE = 25;
static const int BPX = 32;
static const int RADIUS = 2000;
static const int SIZE_CUBE = 64;
static const int WIDTH = SIZE_CUBE * 13;
static const int HEIGHT = SIZE_CUBE * 14;
static const float ratio = 255.0 / (float)HEIGHT / 1;

sfVertexArray *create_vertex_array(sfVector2f, float, float, sfColor);
void display_rays(sfRenderWindow *, ray_t *);
ray_t *new_rays(size_t, sfVector2f, float);
ray_t *rays_on_wall(sfVector2f, pnt_t *);
ray_t *create_ray(ray_t *, sfVector2f, sfVector2f, sfColor);
void destroy_rays(ray_t **);
float dist(sfVector2f, sfVector2f);
ray_t *redirect_rays(sfVector2f, pnt_t *, float);
wall_t *new_walls(char const *);
void display_walls(sfRenderWindow *, wall_t *);
void display_pt(sfRenderWindow *, pnt_t *);
void display_rays(sfRenderWindow *, ray_t *);
void destroy_pt(pnt_t *);
float dist(sfVector2f, sfVector2f);
pnt_t *find_intersections(wall_t *, ray_t *, sfVector2f);
pnt_t *create_point(float, float, sfColor);
void destroy_walls(wall_t *);
