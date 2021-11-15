/*
** EPITECH PROJECT, 2020
** my ls
** File description:
** listing
*/

#include <my.h>

void display_it(struct dirent *content)
{
    char *buf;
    size_t buf_size;

    if (content->d_name[0] != '.') {
        my_putstr(content->d_name);
    }
}

void display_content(content_list_t *content_list, size_t const flag)
{
    if (flag & L_FLAG) {
        print_total(content_list);
        display_ll(content_list, flag);
    }
    else {
        if (content_list) {
            (flag & LITTLE_R_FLAG)
                ? display_content(content_list->next, flag) : flag;
            display_it(content_list->content);
            (content_list->content->d_name[0] != '.')
                ? my_putstr("\n") : content_list;
            (!(flag & LITTLE_R_FLAG))
                ? display_content(content_list->next, flag) : flag;
        }
    }
}

int is_existing(DIR *directory, char *to_list)
{
    if (directory == NULL) {
        write(2, "ls: cannot access '", 20);
        write(2, to_list, my_strlen(to_list));
        write(2, "': No such file or directory\n", 29);
        exit(84);
    }
    return (0);
}

void my_engine(DIR *directory, char *to_list,
                size_t const flag, content_list_t **content_list)
{
    struct dirent *content;

    while ((content = readdir(directory)) != NULL) {
        insert(content_list, content, (!to_list) ? "." : to_list);
        if ((flag & BIG_R_FLAG) && content->d_name[0] != '.') {
            if (to_list[my_strlen(to_list) - 1] != '/')
                to_list = my_strcat(to_list, "/");
            listing(my_strcat(to_list, content->d_name), flag);
        }
    }
}

void listing(char *to_list, size_t const flag)
{
    DIR *directory;
    content_list_t *content_list = NULL;

    if (!to_list)
        directory = opendir(".");
    else
        directory = opendir(to_list);
    if ((flag & BIG_R_FLAG) && directory == NULL)
        return;
    if (is_existing(directory, to_list) == 84)
        return;
    my_engine(directory, to_list, flag, &content_list);
    manage_big_r_print(to_list, flag);
    (flag & 8) ? (content_list = sort_list_t_flag(content_list)) :
        (content_list = sort_list_alph(content_list));
    display_content(content_list, flag);
    closedir(directory);
    if (flag & BIG_R_FLAG)
        my_putstr("\n");
}
