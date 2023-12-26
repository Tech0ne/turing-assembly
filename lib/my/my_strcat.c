/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Concatenate strings
*/

#include "includes.h"

char               *my_strcat(char *dest, const char *src)
{
    int length = my_strlen(dest);
    for (int i = 0; src[i]; i++)
        dest[length + i] = src[i];
    dest[length + my_strlen(src)] = '\0';

    return dest;
}

char               *my_strncat(char *dest, const char *src, int n)
{
    int dest_length = my_strlen(dest), i = 0;
    for (; src[i] && i < n; i++)
        dest[dest_length + i] = src[i];

    if (src[i] != '\0')
        dest[dest_length + i] = '\0';

    return dest;
}
