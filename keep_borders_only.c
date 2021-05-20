/*
** EPITECH PROJECT, 2021
** keep borders only
** File description:
** replace all characters which are not SPACES, '\n', '#' and '\0' by SPACES
*/

#include "include/my.h"

char *keep_borders_only(char *map)
{
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'O' || map[i] == 'X' || map[i] == 'P') {
            map[i] = ' ';
        }
    }
    return (map);
}