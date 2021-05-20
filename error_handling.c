/*
** EPITECH PROJECT, 2021
** error_handling
** File description:
** check the arguments and the file
*/

#include "include/my.h"
#include <stdlib.h>

int error_handling(int ac, char **av, char **map, lines_t *lineset)
{
    if (ac != 2) {
        my_puterr("Invalid number of arguments\n");
        return (84);
    }
    if ((*map = file_reader(av[1])) == NULL) {
        my_puterr("Invalid file\n");
        return (84);
    }
    if (is_map_valid(*map, lineset, 0) == 0) {
        free(*map);
        return (84);
    }
    return (0);
}