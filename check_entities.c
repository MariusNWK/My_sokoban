/*
** EPITECH PROJECT, 2021
** check entities
** File description:
** check if there is a player 'P' and at least one box 'X' and one checkpo
*/

#include "include/my.h"

int check_entities(char *map)
{
    int player = 0;
    int box = 0;
    int cp = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'P')
            player++;
        if (map[i] == 'X')
            box++;
        if (map[i] == 'O')
            cp++;
    }
    if (player != 1)
        return (0);
    if (box < 1 || box != cp)
        return (0);
    if (cp < 1 || cp != box)
        return (0);
    return (1);
}