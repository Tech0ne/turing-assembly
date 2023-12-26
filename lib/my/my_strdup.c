/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Duplicate string
*/

#include "includes.h"

char               *my_strdup(const char *str)
{
    char *dup = malloc(my_strlen(str) + 1);
    my_strcpy(dup, str);
    return dup;
}

char               *my_strndup(const char *str, int n)
{
    int size = n;
    if ((my_strlen(str)) < size)
        size = my_strlen(str);
    char *new = malloc(size + 1);
    for (int i = 0; i < (size + 1); i++)
        new[i] = str[i];
    new[size] = '\0';
    return new;
}
