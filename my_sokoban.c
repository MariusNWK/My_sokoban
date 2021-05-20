/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** main function of my_sokoban game
*/

#include "include/my.h"

int my_sokoban(char *borders, entities_t *entities, lines_t set)
{
    int status = 0;

    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    status = animate_screen(stdscr, borders, entities, set);
    endwin();
    return (status);
}