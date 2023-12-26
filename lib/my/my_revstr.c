/*
** EPITECH PROJECT, 2023
** MyPrintf
** File description:
** my_revstr
*/

#include "includes.h"

char               *my_revstr(char *str)
{
    char *dup = my_strdup(str);
    int length = my_strlen(dup);
    char c;
    for (int i = 0; i < (length / 2); i++) {
        c = dup[i];
        dup[i] = dup[length - 1 - i];
        dup[length - 1 - i] = c;
    }
    return dup;
}
