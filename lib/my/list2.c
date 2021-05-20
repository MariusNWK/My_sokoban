/*
** EPITECH PROJECT, 2020
** list2
** File description:
** pushswap
*/

#include <stdlib.h>
#include <unistd.h>
#include "../../include/my.h"

coords_t get_at(list_t *list, int pos)
{
    int i = 0;
    coords_t error = {-1, -1};

    if (is_empty_list(list)) {
        return (error);
    }
    while (i < pos) {
        i++;
        list = list->next;
    }
    return (list->data);
}

void set_at(list_t *list, coords_t data, int pos)
{
    int i = 0;

    if (is_empty_list(list)) {
        return;
    }
    while (i < pos) {
        i++;
        list = list->next;
    }
    list->data = data;
}

list_t *free_at(list_t *list, int pos)
{
    list_t *prec = list;
    list_t *cur = list;
    int i = 0;

    if (is_empty_list(list)) {
        return (NULL);
    }
    if (pos == 0) {
        list = list->next;
        free(cur);
        return (list);
    }
    while (i < pos) {
        i++;
        prec = cur;
        cur = cur->next;
    }
    prec->next = cur->next;
    free(cur);
    return (list);
}

list_t *free_list(list_t *list)
{
    list_t *tmp = NULL;

    while (list) {
        tmp = list->next;
        free(list);
        list = tmp;
    }
    return (list);
}

void print_list(list_t *list)
{
    while (list) {
        my_putstr("position x : ");
        my_putnbr(list->data.x);
        my_putstr(" *** ");
        my_putstr("position y : ");
        my_putnbr(list->data.y);
        my_putchar('\n');
        list = list->next;
    }
}