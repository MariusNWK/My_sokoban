/*
** EPITECH PROJECT, 2021
** define entities
** File description:
** return a type entities_t which contains all the coords of the player, t
*/

#include "include/my.h"

coords_t define_coords(int x, int y)
{
    coords_t coords;

    coords.x = x;
    coords.y = y;
    return (coords);
}

void each_entity(int i, lines_t set, entities_t *ent)
{
    for (int j = 0; j < set.lines_len[i]; j++) {
        if (set.lines[i][j] == '#')
            ent->walls = add_at(ent->walls, define_coords(j, i), 0);
        if (set.lines[i][j] == 'P')
            ent->player = define_coords(j, i);
        if (set.lines[i][j] == 'X')
            ent->boxes = add_at(ent->boxes, define_coords(j, i), 0);
        if (set.lines[i][j] == 'O')
            ent->cp = add_at(ent->cp, define_coords(j, i), 0);
    }
}

entities_t define_entities(lines_t set)
{
    entities_t ent;
    ent.walls = NULL;
    ent.boxes = NULL;
    ent.cp = NULL;

    for (int i = 0; i < set.lines_nbr; i++) {
        each_entity(i, set, &ent);
    }
    return (ent);
}