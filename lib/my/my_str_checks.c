/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Some checks, such as is_letter, or is_upper...
*/

#include "includes.h"

bool                my_str_is_letters(const char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
            return false;
    return true;
}

bool                my_str_is_numbers(const char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return false;
    return true;
}

bool                my_str_is_upper(const char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            return false;
    return true;
}

bool                my_str_is_lower(const char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            return false;
    return true;
}

bool                my_str_isprintable(const char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < 32 || str[i] > 126)
            return false;
    return true;
}
