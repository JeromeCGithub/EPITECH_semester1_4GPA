/*
** EPITECH PROJECT, 2019
** str_cat
** File description:
** Concatenates two string.
*/

#include <my.h>

char *my_strcat(char *line1, char *line2)
{
    int index = 0;
    int index_result = 0;
    int size = 0;
    char *result;

    if (line1 == NULL || line2 == NULL)
        return ((line1 == NULL) ? line2 : line1);
    for (size = 0 ; line1[size] != '\0' ; size++);
    for (index = 0 ; line2[index] != '\0' ; size++, index++);
    result = malloc(sizeof(char) * (size + 1));
    if (result == NULL)
        return (NULL);
    for (index = 0 ; line1[index] != '\0' ; index++, index_result++)
        result[index_result] = line1[index];
    for (index = 0 ; line2[index] != '\0' ; index++, index_result++)
        result[index_result] = line2[index];
    result[index_result] = '\0';
    return (result);
}
