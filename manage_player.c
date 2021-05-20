/*
** EPITECH PROJECT, 2021
** manage player
** File description:
** move the player, display the player, store the position of the player
*/

#include "include/my.h"

int are_coords_equal(coords_t coords1, coords_t coords2)
{
    if (coords1.x == coords2.x && coords1.y == coords2.y) {
        return (1);
    }
    return (0);
}

void check_all_diections(direction_t direction, entities_t *ent)
{
    if (direction.left)
        ent->player.x += 1;
    if (direction.up)
        ent->player.y += 1;
    if (direction.right)
        ent->player.x -= 1;
    if (direction.down)
        ent->player.y -= 1;
}

void is_player_in_wall(entities_t *ent, direction_t direction)
{
    int len = length_list(ent->walls);
    coords_t coords_player = {ent->player.x, ent->player.y};
    coords_t coords_wall;

    for (int i = 0; i < len; i++) {
        coords_wall = get_at(ent->walls, i);
        if (are_coords_equal(coords_wall, coords_player))
            check_all_diections(direction, ent);
    }
}

void manage_player(entities_t *ent, int key)
{
    direction_t direction = {0, 0, 0, 0};

    if (key == KEY_LEFT) {
        ent->player.x -= 1;
        direction.left = 1;
    }
    if (key == KEY_UP) {
        ent->player.y -= 1;
        direction.up = 1;
    }
    if (key == KEY_RIGHT) {
        ent->player.x += 1;
        direction.right = 1;
    }
    if (key == KEY_DOWN) {
        ent->player.y += 1;
        direction.down = 1;
    }
    is_player_in_wall(ent, direction);
}