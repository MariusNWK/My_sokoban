/*
** EPITECH PROJECT, 2021
** copy_map
** File description:
** copy the map
*/

#include "include/my.h"

char **copy_map(char **lines, int *lines_len, char *map, lp_t lp)
{
    if (lp.j == lines_len[lp.i])
        lines[lp.i][lp.j] = '\0';
    else
        lines[lp.i][lp.j] = map[lp.k];
    return (lines);
}