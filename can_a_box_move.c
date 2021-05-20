/*
** EPITECH PROJECT, 2021
** can a box move
** File description:
** check there is still at least one box which can move. Return 1 if yes,
*/

#include "include/my.h"

vehor_t define_vehor(int horiz_1, int vertic_1, int horiz_2, int vertic_2)
{
    vehor_t vehor;

    vehor.horiz_1 = horiz_1;
    vehor.horiz_2 = horiz_2;
    vehor.vertic_1 = vertic_1;
    vehor.vertic_2 = vertic_2;
    return (vehor);
}

int is_box_blocked(vehor_t v, coords_t box_coords)
{
    if ((mvinch(box_coords.y + v.vertic_1, box_coords.x + v.horiz_1) == '#' ||
    mvinch(box_coords.y + v.vertic_1, box_coords.x + v.horiz_1) == 'X') &&
    (mvinch(box_coords.y + v.vertic_2, box_coords.x + v.horiz_2) == '#' ||
    mvinch(box_coords.y + v.vertic_2, box_coords.x + v.horiz_2) == 'X'))
        return (1);
    return (0);
}

int boxes_blocked_status(int boxes_blocked, coords_t box_coords)
{
    if (is_box_blocked(define_vehor(1, 0, 0, 1), box_coords)) {
        boxes_blocked++;
        return (boxes_blocked);
    }
    if (is_box_blocked(define_vehor(0, 1, -1, 0), box_coords)) {
        boxes_blocked++;
        return (boxes_blocked);
    }
    if (is_box_blocked(define_vehor(-1, 0, 0, -1), box_coords)) {
        boxes_blocked++;
        return (boxes_blocked);
    }
    if (is_box_blocked(define_vehor(0, -1, 1, 0), box_coords)) {
        boxes_blocked++;
        return (boxes_blocked);
    }
    return (boxes_blocked);
}

int can_a_box_move(entities_t *ent)
{
    int boxes_nbr = length_list(ent->boxes);
    int boxes_blocked = 0;
    coords_t box_coords;

    for (int i = 0; i < boxes_nbr; i++) {
        box_coords = get_at(ent->boxes, i);
        boxes_blocked = boxes_blocked_status(boxes_blocked, box_coords);
    }
    if (boxes_blocked == boxes_nbr)
        return (0);
    return (1);
}