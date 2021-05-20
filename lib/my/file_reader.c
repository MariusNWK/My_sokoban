/*
** EPITECH PROJECT, 2021
** file_reader
** File description:
** myrunner
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>

size_t getfilesize(char const *filepath)
{
    struct stat st;

    if (stat(filepath, &st) != 0)
        return (0);
    return (st.st_size);
}

char *file_reader(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *str;

    if (fd == -1)
        return (NULL);
    if ((str = malloc(getfilesize(filepath) + 1)) == NULL)
        return (NULL);
    read(fd, str, getfilesize(filepath));
    str[getfilesize(filepath)] = '\0';
    close(fd);
    return (str);
}