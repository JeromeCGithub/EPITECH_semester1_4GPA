/*
** EPITECH PROJECT, 2019
** langage
** File description:
** langue
*/

int is_low_orup(char **av, int i)
{
    if (av[i][0] <= 'Z' && av[i][0] >= 'A')
        return ((int)av[i][0] - 65);
    else if (av[i][0] <= 'z' && av[i][0] >= 'a')
        return ((int)av[i][0] - 97);
}

int en(char **av)
{
    int average = 0;
    int taben[26] = {8167, 1492, 2782, 4253, 12702, 2228, 2015, 6094, 6966,
                    153, 772, 4025, 2406, 6749, 7507, 1929, 95, 5987, 6327,
                    9056, 2758, 978, 2360, 150, 1974, 74};
    for (int i = 2 ; av[i] != 0 ; i++)
        average += taben[is_low_orup(av, i)];
    return (average);
}

int fr(char **av)
{
    int average = 0;
    int tabfr[26] = {7636, 901, 3260, 3669, 14715, 1066, 866, 737, 7529, 613,
                    74, 5456, 2968, 7095, 5796, 2521, 1362, 6693, 7948, 7244,
                    6311, 1838, 49, 427, 128, 326};
    for (int i = 2 ; av[i] != 0 ; i++)
        average += tabfr[is_low_orup(av, i)];
    return (average);
}

int ge(char **av)
{
    int average = 0;
    int tabge[26] = {6516, 1886, 2732, 5076, 16396, 1656, 3009, 4577, 6550,
                    268, 1417, 3437, 2534, 9776, 2594, 670, 18, 7003, 7270,
                    6154, 4166, 846, 1921, 34, 39, 1134};
    for (int i = 2 ; av[i] != 0 ; i++)
        average += tabge[is_low_orup(av, i)];
    return (average);
}

int sp(char **av)
{
    int average = 0;
    int tabsp[26] = {11525, 2215, 4019, 5010, 12181, 692, 1768, 703, 6247, 493,
                    11, 4967, 3157, 6712, 8683, 2510, 877, 6871, 7977, 4632,
                    2927, 1138, 17, 215, 1008, 467};
    for (int i = 2 ; av[i] != 0 ; i++)
        average += tabsp[is_low_orup(av, i)];
    return (average);
}
