/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** mysh
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i]) {
        i++;
    }
    return (i);
}
