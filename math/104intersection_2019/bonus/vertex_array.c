/*
** EPITECH PROJECT, 2019
** ray_casting
** File description:
** vertex_array
*/

#include <my.h>

sfVertexArray *create_vertex_array(sfVector2f start, float x2, float y2, sfColor color)
{
    sfVertexArray *vertex = sfVertexArray_create();
    sfVector2f vec = {x2 - start.x, y2 - start.y};
    sfVertex new_point;

    new_point.color = color;
    for (float i = 0; i < 1; i += 0.001) {
        new_point.position.x = vec.x * i + start.x;
        new_point.position.y = vec.y * i + start.y;
        sfVertexArray_append(vertex, new_point);
    }
    return (vertex);
}
