/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** delete node
*/

#include <my.h>

bird_t *delete_bird(bird_t *obs, int compteur)
{
    bird_t *temp = obs;
    bird_t *prev = obs;
    int i = 0;

    if (compteur == 0) {
        obs = temp->next;
        return (obs);
    }
    for (i = 0 ; temp != NULL && compteur != i ; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return (NULL);
    prev->next = temp->next;
    return (obs);
}

obstacle_t *delete_node(obstacle_t *obs, int compteur, sfVector2f pos)
{
    obstacle_t *temp = obs;
    obstacle_t *prev = obs;
    int i = 0;

    if (pos.x > -50)
        return (obs);
    if (compteur == 0) {
        obs = temp->next_obs;
        return (obs);
    }
    for (i = 0 ; temp != NULL && compteur != i ; i++) {
        prev = temp;
        temp = temp->next_obs;
    }
    if (temp == NULL)
        return (NULL);
    prev->next_obs = temp->next_obs;
    return (obs);
}
