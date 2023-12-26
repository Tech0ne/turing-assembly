/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Check if char in str, and more
*/

#include "includes.h"

int                 my_str_get_index(const char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return i;
    return -1;
}

bool                my_str_are_only(const char *str, const char *ref)
{
    for (int i = 0; str[i]; i++)
        if (my_str_get_index(ref, str[i]) == -1)
            return false;
    return true;
}
