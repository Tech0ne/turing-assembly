/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Capitalize a string (maj for first letters)
*/

#include "includes.h"

static void         charup(char *c)
{
    if (*c >= 'a' && *c <= 'z')
        *c -= 32;
}

static void         charlow(char *c)
{
    if (*c >= 'A' && *c <= 'Z')
        *c += 32;
}

char                *my_strcapitalize(char *str)
{
    char last = '\0';

    for (int i = 0; str[i]; i++) {
        charup(&str[i]);
        if (last >= '0' && last <= '9')
            charlow(&str[i]);
        if (last >= 'A' && last <= 'Z')
            charlow(&str[i]);
        if (last >= 'a' && last <= 'z')
            charlow(&str[i]);
        last = str[i];
    }
    return str;
}
