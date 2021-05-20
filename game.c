/*
** EPITECH PROJECT, 2021
** game
** File description:
** display the borders, move the 'P' character and move the 'X' boxes
*/

#include "include/my.h"

int game(char *borders, entities_t *ent, int key)
{
    mvprintw(0, 0, borders);
    ent->prec_player = define_coords(ent->player.x, ent->player.y);
    manage_player(ent, key);
    manage_cp(ent);
    manage_boxes(ent, key);
    mvprintw(ent->player.y, ent->player.x, "P");
    if (are_all_boxes_stored(ent)) {
        return (0);
    }
    if (can_a_box_move(ent) == 0) {
        return (1);
    }
    return (2);
}