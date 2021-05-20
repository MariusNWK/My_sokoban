/*
** EPITECH PROJECT, 2021
** main
** File description:
** main of my_sokoban
*/

#include "include/my.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    char *map;
    int is_win = 0;
    lines_t set;
    entities_t ent;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr(file_reader("./usage"));
        return (0);
    }
    if (error_handling(ac, av, &map, &set) == 84) {
        return (84);
    }
    ent = define_entities(set);
    is_win = my_sokoban(keep_borders_only(map), &ent, set);
    free_lines_memory(set.lines_nbr, set.lines_len, set.lines);
    ent.walls = free_list(ent.walls);
    ent.boxes = free_list(ent.boxes);
    ent.cp = free_list(ent.cp);
    free(map);
    return (is_win);
}