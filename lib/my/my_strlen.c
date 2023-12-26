/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Length of string
*/

#include "includes.h"

int                 my_strlen(const char *str)
{
    int i = 0;
    for (; str[i]; i++);
    return i;
}

int                 my_strlen_to_char(const char *str, char c)
{
    int i = 0;
    for (; str[i] != c && str[i]; i++);
    return i;
}
