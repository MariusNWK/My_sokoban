/*
** EPITECH PROJECT, 2021
** are all boxes stored
** File description:
** check if all the boxes are stored. If yes return 1, else return 0
*/

#include "include/my.h"

int is_box_stored(int len, entities_t *ent,
coords_t box_coords, int boxes_stored)
{
    coords_t cp_coords;

    for (int j = 0; j < len; j++) {
        cp_coords = get_at(ent->cp, j);
        if (are_coords_equal(box_coords, cp_coords))
            boxes_stored++;
    }
    return (boxes_stored);
}

int are_all_boxes_stored(entities_t *ent)
{
    int len = length_list(ent->boxes);
    coords_t box_coords;
    int boxes_stored = 0;

    for (int i = 0; i < len; i++) {
        box_coords = get_at(ent->boxes, i);
        boxes_stored = is_box_stored(len, ent, box_coords, boxes_stored);
    }
    if (boxes_stored == len)
        return (1);
    return (0);
}