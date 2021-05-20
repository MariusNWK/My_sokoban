/*
** EPITECH PROJECT, 2021
** manage cp
** File description:
** manages the storage locations displays
*/

#include "include/my.h"

void manage_cp(entities_t *ent)
{
    int len = length_list(ent->cp);
    coords_t coords;

    for (int i = 0; i < len; i++) {
        coords = get_at(ent->cp, i);
        mvprintw(coords.y, coords.x, "O");
    }
}