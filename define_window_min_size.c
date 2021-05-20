/*
** EPITECH PROJECT, 2021
** define window minimum size
** File description:
** define the biggest value of x and y of the map which are the min values
*/

#include "include/my.h"

int define_min_x(int k, coords_t *min, char *map, int i)
{
    if (map[i] != '\n')
        k++;
    else {
        if (k >= min->x)
            min->x = k + 1;
        k = 0;
    }
    return (k);
}

coords_t define_window_min_size(char *map)
{
    coords_t min = {0, 0};

    for (int i = 0, k = 0; map[i] != '\0'; i++) {
        k = define_min_x(k, &min, map, i);
    }
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n')
            min.y++;
        if (map[i] != '\n' && map[i + 1] == '\0')
            min.y++;
    }
    return (min);
}