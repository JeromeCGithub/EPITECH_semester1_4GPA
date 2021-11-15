/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** main
*/

#include <my.h>

int print_when_nothing(void)
{
    my_putstr("./my_runner: Bad argument, need a default map.\nRetry with -h");
    return (84);
}

int print_h(char const *str)
{
    if (my_strlen(str) < 2)
        return (print_when_nothing());
    if (str[0] == '-' && str[1] == 'h' && str[2] == '\0') {
        my_putstr("A christmas runner made with CSFML.\n\n");
        my_putstr("USAGE:\n\n./my_runner map/map0X.map");
        my_putstr(" | Remplace 'X' by a digit between 0 and 6 to set the ");
        my_putstr("default map\n\nHOW TO PLAY:\n\n");
        my_putstr("Each map have different level of difficulty and speed.\n");
        my_putstr("You can select any level by changing the first argv. ");
        my_putstr("Then, click on play, you need to jump or slide to dodge.");
        my_putstr("\nYou can see your score on the top of the screen.");
        my_putstr("\n\nTo jump : UP Arrow\nTo slide : DOWN Arrow\n");
        my_putstr("Press escape for pause");
        my_putstr("\n\nBe carefull to the bird, if you touch one, you can ");
        my_putstr("loose, or win some score point. At you to be lucky !");
        my_putstr("\n\nIn the menu you can choose the infinity mode. Try it !");
        my_putstr("\n\nOPTION:\n\n-h            Print the usage and quit.");
        return (84);
    }
    return (0);
}

map_t *load_map(char const *file_name, int inf)
{
    char *speed = NULL;
    map_t *map = malloc(sizeof(map_t));
    FILE *fd = fopen(file_name, "r");
    size_t size = 0;
    size_t size2 = 0;

    map->map_name = my_strdup(file_name);
    map->map = NULL;
    map->speed = 0;
    if (fd <= 0) {
        print_when_nothing();
        return (NULL);
    }
    getline(&map->map, &size, fd);
    getline(&speed, &size2, fd);
    map->speed = my_atoi(speed);
    fclose(fd);
    if (inf)
        map->inf = 10;
    return (map);
}

int get_infinite(int ac, char **av)
{
    for (int i = 0 ; av[i] ; i++) {
        if (av[i][0] == '-' && av[i][1] == 'i')
            return (1);
    }
    return (0);
}

int main(int ac, char **av, char **envp)
{
    sfRenderWindow *window;
    map_t *map = NULL;
    int infinity = get_infinite(ac, av);

    if (ac < 2)
        return (print_when_nothing());
    if (print_h(av[1]) == 84)
        return (0);
    map = load_map(av[1], infinity);
    if (map == NULL || check_env(envp))
        return (84);
    map->map_name = av[1];
    window = sfRenderWindow_create(MODE, "Christmas Runner",
                                    sfResize | sfClose, NULL);
    if (!window)
        return (84);
    sfRenderWindow_setFramerateLimit(window, 60);
    menu_loop(window, map, infinity);
    sfRenderWindow_destroy(window);
    return (0);
}
