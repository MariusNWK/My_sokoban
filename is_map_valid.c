/*
** EPITECH PROJECT, 2021
** is_map_valid
** File description:
** check if the string representing a map is valid. Return 1 if valid, 0 if not
*/

#include "include/my.h"

int is_char_wrong(char *chars, char *map, int i)
{
    for (int j = 0, n = 0; chars[j] != '\0'; j++) {
        if (map[i] != chars[j])
            n++;
        if (n == 6)
            return (1);
    }
    return (0);
}

int check_chars(char *map)
{
    char *chars = "\n #XOP";

    for (int i = 0; map[i] != '\0'; i++) {
        if (is_char_wrong(chars, map, i))
            return (0);
    }
    return (1);
}

int is_map_valid(char *map, lines_t *lineset, int criterion)
{
    if (check_chars(map) == 0) {
        if (criterion == 0)
            my_puterr("Invalid character(s)\n");
        return (0);
    }
    if (check_border(map, lineset) == 0) {
        if (criterion == 0)
            my_puterr("Invalid limits\n");
        return (0);
    }
    if (check_entities(map) == 0) {
        if (criterion == 0)
            my_puterr("Invalid entities\n");
        return (0);
    }
    return (1);
}