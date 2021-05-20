/*
** EPITECH PROJECT, 2021
** manages boxes
** File description:
** display boxes, change boxes positions
*/

#include "include/my.h"

int check_if_valid_coords(entities_t *ent, coords_t *coords, coords_t p_coords)
{
    coords_t wall_coords;
    coords_t box_coords;

    for (int i = 0, len = length_list(ent->walls); i < len; i++) {
        wall_coords = get_at(ent->walls, i);
        if (are_coords_equal(wall_coords, *coords)) {
            *coords = define_coords(p_coords.x, p_coords.y);
            ent->player = define_coords(ent->prec_player.x, ent->prec_player.y);
            return (0);
        }
    }
    for (int i = 0, len = length_list(ent->boxes); i < len; i++) {
        box_coords = get_at(ent->boxes, i);
        if (are_coords_equal(box_coords, *coords)) {
            *coords = define_coords(p_coords.x, p_coords.y);
            ent->player = define_coords(ent->prec_player.x, ent->prec_player.y);
            return (0);
        }
    }
    return (1);
}

void move_the_box(lp_t lp, coords_t *coords, coords_t pcoords, entities_t *ent)
{
    if (lp.key == KEY_RIGHT)
        coords->x += 1;
    if (lp.key == KEY_UP)
        coords->y -= 1;
    if (lp.key == KEY_LEFT)
        coords->x -= 1;
    if (lp.key == KEY_DOWN)
        coords->y += 1;
    if (check_if_valid_coords(ent, coords, pcoords))
        set_at(ent->boxes, *coords, lp.i);
}

void manage_boxes(entities_t *ent, int key)
{
    int len = length_list(ent->boxes);
    coords_t coords;
    coords_t prec_coords;
    lp_t lp = {key, 0};

    for (int i = 0; i < len; i++) {
        coords = get_at(ent->boxes, i);
        prec_coords = get_at(ent->boxes, i);
        if (are_coords_equal(ent->player, coords)) {
            lp.i = i;
            move_the_box(lp, &coords, prec_coords, ent);
        }
        mvprintw(coords.y, coords.x, "X");
    }
}