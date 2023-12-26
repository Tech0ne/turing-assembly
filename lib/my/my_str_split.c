/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Split a string by given sub-string
*/

#include "includes.h"

char              **my_str_split(char *str, const char *sub)
{
    if (!(str || sub))
        return NULL;
    int nb_sub = my_str_counts(str, sub);
    char **map = malloc(sizeof(char *) * (nb_sub + 2));
    int pos = 0, size = 0;
    map[nb_sub + 1] = NULL;
    for (int i = 0; i < nb_sub; i++) {
        size = my_str_find(&str[pos], sub);
        map[i] = my_strndup(&str[pos], size);
        pos += size;
        pos += my_strlen(sub);
    }
    map[nb_sub] = my_strdup(&str[pos]);
    return map;
}
