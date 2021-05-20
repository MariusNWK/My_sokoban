/*
** EPITECH PROJECT, 2021
** free pos and reduce len
** File description:
** free the position and reduce the len of this list of one
*/

#include "include/my.h"

int free_pos_and_reduce_len(list_t **positions, int j, int list_len)
{
    *positions = free_at(*positions, j);
    list_len--;
    return (list_len);
}