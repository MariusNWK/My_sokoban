/*
** EPITECH PROJECT, 2021
** search same coords
** File description:
** seach the coords of the walls of a list to find which ones are equal to
*/

#include "include/my.h"

int are_same_coords(int i, int j, list_t *list1, list_t *list2)
{
    coords_t coords_i = get_at(list1, i);
    coords_t coords_j = get_at(list2, j);

    if (coords_i.x == coords_j.x && coords_i.y == coords_j.y) {
        return (1);
    }
    return (0);
}

list_t *search_same_coords(list_t *positions, int i, list_t *positions_to_free)
{
    for (int j = 0, list_len = length_list(positions); j < list_len; j++) {
        if (are_same_coords(i, j, positions_to_free, positions)) {
            list_len = free_pos_and_reduce_len(&positions, j, list_len);
            j--;
        }
    }
    return (positions);
}