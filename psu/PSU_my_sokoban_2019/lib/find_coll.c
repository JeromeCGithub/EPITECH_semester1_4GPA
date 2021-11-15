/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** find coll
*/

int find_coll(char *buff)
{
    int i = 0;
    int col = 0;
    int collumn = 0;

    for (col = 0 ; buff[col] != '\0' ; col++) {
        if (buff[col] == '\n') {
            (col > collumn) ? (collumn = i) : col;
            i = 0;
        }
        i++;
    }
    return (collumn);
}
