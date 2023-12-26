/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Locate a sub-string in a string
*/

#include "includes.h"

int                 my_str_find(char *str, const char *sub)
{
    bool found;
    int length = my_strlen(str) - my_strlen(sub) + 1;
    for (int i = 0; i < length; i++) {
        found = true;
        for (int j = 0; sub[j]; j++)
            found = found ? (str[i + j] == sub[j]) : found;
        if (found)
            return i;
    }
    return -1;
}
