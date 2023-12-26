/*
** EPITECH PROJECT, 2023
** FullLib
** File description:
** my_str_replace
*/

#include "includes.h"

char               *my_str_replace(char *str, char *sep, char *to)
{
    char *dup = my_strdup(str);
    char **splited = my_str_split(dup, sep);
    free(dup);
    char *result = my_str_join(splited, to);
    for (int i = 0; splited[i]; i++)
        free(splited[i]);
    free(splited);
    return result;
}
