/*
** EPITECH PROJECT, 2019
** get next line
** File description:
** get next line dot c
*/

#include <my.h>

void put_in_buffer(char **buffer, int fd)
{
    int size = 0;

    *buffer = malloc(sizeof(char) * (READ_SIZE + 1));
    if (*buffer == NULL)
        return;
    size = read(fd, *buffer, READ_SIZE);
    if (size < 0)
        return;
    (*buffer)[size] = '\0';
}

char *put_result(char **buffer)
{
    int i = 0;
    char *result = malloc(sizeof(char) * (READ_SIZE + 1));

    if (result == NULL)
        return (NULL);
    for (i = 0 ; *buffer[0] != '\0' && *buffer[0] != '\n' ; i++) {
        result[i] = *buffer[0];
        *buffer += 1;
    }
    if (*buffer[0] == '\n')
        result[i] = '\n';
    else
        result[i] = '\0';
    return (result);
}

int is_n(char *line)
{
    for (int i = 0 ; line[i] != '\0' ; i++) {
        if (line[i] == '\n')
            return (1);
    }
    return (0);
}

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

char *get_next_line(int fd)
{
    int i = 0;
    char *line = NULL;
    int size = 0;
    int is_it_n = 0;
    static char *buffer;

    if (fd < 0 || READ_SIZE < 1)
        return (NULL);
    if (buffer == NULL || buffer[0] == '\0')
        put_in_buffer(&buffer, fd);
    if (buffer == NULL || buffer[0] == '\0')
        return (NULL);
    line = put_result(&buffer);
    if (buffer[0] == '\n')
        buffer += 1;
    if ((is_it_n = is_n(line)) == 1) {
        for (i = 0 ; line[i] != '\0' && line[i] != '\n' ; i++);
        line[i] = '\0';
    }
    return ((is_it_n) ? line : my_strcat(line, get_next_line(fd)));
}
