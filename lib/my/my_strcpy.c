/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Copy src to dest / copy x chars from src to dest
*/

#include "includes.h"

char               *my_strcpy(char *dest, const char *src)
{
    for (int i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[my_strlen(src)] = '\0';

    return dest;
}

char               *my_strncpy(char *dest, const char *src, int n)
{
    int i = 0;
    for (; src[i] && i < n; i++)
        dest[i] = src[i];
    dest[i] = (!src[i] || i >= n) ? '\0' : dest[i];

    return dest;
}
