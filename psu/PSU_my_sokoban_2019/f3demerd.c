/*
** EPITECH PROJECT, 2019
** dw\a
** File description:
** dwa
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
    FILE *fd;
    char *buffer = NULL;
    ssize_t size = 0;
    
    for (int i = 1; i < ac; i++) {
        fd = fopen(av[i], "r");
        while (getline(&buffer, &size, fd) >= 0) {
            if (strlen(buffer) > 80) {
                printf("error on %s:\n%s", av[i], buffer);
                fclose(fd);
                free(buffer);
                return (1);
            }
                
        }  
        fclose(fd);
    }
    free(buffer);
    return (0);
}
