/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Count occurencies of certain things on a string
*/

#include "includes.h"

int                 my_str_count(const char *str, char c)
{
    int total = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            total++;
    return total;
}

int                 my_str_counts(const char *str, const char *sub)
{
    char *_str = my_strdup(str);
    int total = 0, pos = 0, next_pos = 0;
    while ((next_pos = my_str_find(&_str[pos], sub)) != -1) {
        pos += my_str_find(&_str[pos], sub) + my_strlen(sub);
        total++;
    }
    free(_str);
    return total;
}
