/*
** EPITECH PROJECT, 2021
** check_border
** File description:
** check if the map is delimited by # characters. Return 1 if it does, 0 if not
*/

#include "include/my.h"
#include <stdlib.h>

int count_lines_nbr(char *map)
{
    int lines_nbr = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n') {
            lines_nbr++;
        }
        if (map[i] != '\n' && map[i + 1] == '\0') {
            lines_nbr++;
        }
    }
    return (lines_nbr);
}

int *count_lines_len(char *map, int lines_nbr)
{
    int *lines_len = malloc(sizeof(int) * lines_nbr);

    if (!lines_len)
        return (NULL);
    for (int i = 0, j = 0, len = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n') {
            lines_len[j] = len;
            len = 0;
            j++;
        }
        else {
            len++;
        }
        if (map[i] != '\n' && map[i + 1] == '\0') {
            lines_len[j] = len;
        }
    }
    return (lines_len);
}

char **define_lines(char *map, int lines_nbr, int *lines_len)
{
    char **lines;
    lp_t lp;

    if (!lines_len)
        return (NULL);
    lines = malloc(sizeof(char *) * (lines_nbr + 1));
    if (!lines)
        return (NULL);
    for (int i = 0, k = 0; i < lines_nbr; i++) {
        if ((lines[i] = malloc(sizeof(char) * (lines_len[i] + 1))) == NULL)
            return (NULL);
        for (int j = 0; j <= lines_len[i]; j++, k++) {
            lp.i = i;
            lp.j = j;
            lp.k = k;
            lines = copy_map(lines, lines_len, map, lp);
        }
    }
    lines[lines_nbr] = NULL;
    return (lines);
}

void free_lines_memory(int lines_nbr, int *lines_len, char **lines)
{
    free(lines_len);
    for (int i = 0; i < lines_nbr; i++)
        free(lines[i]);
    free(lines);
}

int check_border(char *map, lines_t *set)
{
    set->lines_nbr = count_lines_nbr(map);
    set->lines_len = count_lines_len(map, set->lines_nbr);
    set->lines = define_lines(map, set->lines_nbr, set->lines_len);

    if (!set->lines) {
        free(set->lines_len);
        return (0);
    }
    return (1);
}