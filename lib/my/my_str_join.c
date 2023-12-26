/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Join a char ** into a char * by filling with another char *
*/

#include "includes.h"

char               *my_str_join(char **map, const char *join)
{
    if (!map || !map[0])
        return NULL;
    int size = 0;
    for (int i = 0; map[i]; i++)
        size += my_strlen(map[i]) + my_strlen(join);
    size -= my_strlen(join);
    size++;

    char *new = malloc(size + 1);
    my_strcpy(new, map[0]);
    for (int i = 1; map[i]; i++) {
        my_strcat(new, join);
        my_strcat(new, map[i]);
    }
    return new;
}
