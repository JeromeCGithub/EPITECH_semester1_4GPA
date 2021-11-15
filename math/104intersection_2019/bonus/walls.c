/*
** EPITECH PROJECT, 2019
** ray_casting
** File description:
** walls
*/

#include <my.h>

static wall_t *create_wall(wall_t *head, sfVector2f start, sfVector2f end, sfColor color)
{
    wall_t *wall = malloc(sizeof(wall_t));

    wall->color = color;
    wall->start.x = start.x;
    wall->start.y = start.y;
    wall->end.x = end.x;
    wall->end.y = end.y;
    wall->vertex = create_vertex_array(start, end.x, end.y, color);
    wall->next = head;
    head = wall;
    return (head);
}

static wall_t *create_cube(wall_t *walls, int column, int line, sfColor color)
{
    sfVector2f start = {0, 0};
    sfVector2f end = {0, 0};

    start.x = SIZE_CUBE * column;
    start.y = SIZE_CUBE * line;
    end.x = SIZE_CUBE * column + SIZE_CUBE;
    end.y = SIZE_CUBE * line;
    walls = create_wall(walls, start, end, sfWhite);
    end.x = SIZE_CUBE * column;
    end.y = SIZE_CUBE * line + SIZE_CUBE;
    walls = create_wall(walls, start, end, color);
    start.x = SIZE_CUBE * column + SIZE_CUBE;
    start.y = SIZE_CUBE * line + SIZE_CUBE;
    end.x = SIZE_CUBE * column;
    end.y = SIZE_CUBE * line + SIZE_CUBE;
    walls = create_wall(walls, start, end, sfWhite);
    end.x = SIZE_CUBE * column + SIZE_CUBE;
    end.y = SIZE_CUBE * line;
    walls = create_wall(walls, start, end, color);
    return (walls);
}

static wall_t *wall_border(wall_t *walls)
{
    sfVector2f start = {0, 0};
    sfVector2f end = {0, 0};

    end.x = WIDTH;
    walls = create_wall(walls, start, end, sfWhite);
    end.x = 0;
    end.y = HEIGHT;
    walls = create_wall(walls, start, end, sfCyan);
    start.x = WIDTH;
    start.y = HEIGHT;
    walls = create_wall(walls, start, end, sfWhite);
    end.x = WIDTH;
    end.y = 0;
    walls = create_wall(walls, start, end, sfCyan);
    return (walls);
}

wall_t *new_walls(char const *filepath)
{
    wall_t *walls = NULL;
    sfVector2f start = {0, 0};
    sfVector2f end = {0, 0};
    FILE *fd = fopen(filepath, "r");
    char *str = NULL;
    int line = 0;
    size_t size = 0;
    int nb_char = 0;

    do {
        nb_char = getline(&str, &size, fd);
        for (int i = 0; str[i]; i++) {
            if (str[i] == '1' && nb_char > 0)
                walls = create_cube(walls, i, line, sfColor_fromRGBA(255, 0, 0, 255));
            if (str[i] == '2' && nb_char > 0)
                walls = create_cube(walls, i, line, sfColor_fromRGBA(0, 255, 0, 255));
            if (str[i] == '3' && nb_char > 0)
                walls = create_cube(walls, i, line, sfColor_fromRGBA(0, 0, 255, 255));
        }
        line++;
    } while (nb_char > 0);
    fclose(fd);
    walls = wall_border(walls);
    return (walls);
}

void destroy_walls(wall_t *walls)
{
    wall_t *next = NULL;

    for (wall_t *actual = walls; actual; actual = next) {
        next = actual->next;
        sfVertexArray_destroy(actual->vertex);
        free(actual);
    }
}
