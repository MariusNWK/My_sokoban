/*
** EPITECH PROJECT, 2021
** animate screen
** File description:
** display the game
*/

#include "include/my.h"

entities_t reset_ent(entities_t ent, lines_t set)
{
    ent.walls = free_list(ent.walls);
    ent.boxes = free_list(ent.boxes);
    ent.cp = free_list(ent.cp);
    ent = define_entities(set);
    return (ent);
}

int animate_screen(WINDOW *stdscr, char *borders, entities_t *ent, lines_t set)
{
    coords_t min = define_window_min_size(borders);
    coords_t size = {0, 0};
    char *instruction = "Enlarge the terminal";
    int len = my_strlen(instruction);
    int key = 0;
    int status = 2;

    do {
        erase();
        getmaxyx(stdscr, size.y, size.x);
        if (key == ' ')
            *ent = reset_ent(*ent, set);
        if (min.x > size.x || min.y > size.y)
            mvprintw(size.y / 2, size.x / 2 - len / 2, instruction);
        else
            status = game(borders, ent, key);
        refresh();
        if (status != 2)
            break;
    } while ((key = getch()) != 'q');
    return (status);
}