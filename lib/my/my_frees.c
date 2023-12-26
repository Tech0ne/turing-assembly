/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_frees
*/

#include "includes.h"

void                free_char_map(char **map)
{
    for (int i = 0; map[i]; i++) free(map[i]);
    free(map);
}

void                free_int_map(int **map)
{
    for (int i = 0; map[i]; i++) free(map[i]);
    free(map);
}
