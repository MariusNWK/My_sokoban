/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** display a string
*/

#include "../../include/my.h"
#include <unistd.h>

void my_putstr(char *str)
{
    int len = my_strlen(str);

    write(1, str, len);
}
