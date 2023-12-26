/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Compare to strings / on x chars
*/

#include "includes.h"

int                 my_strcmp(const char *s1, const char *s2)
{
    for (int i = 0; s1[i] || s2[i]; i++)
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    return 0;
}

int                 my_strncmp(const char *s1, const char *s2, int n)
{
    for (int i = 0; (s1[i] || s2[i]) && i < n; i++)
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    return 0;
}
