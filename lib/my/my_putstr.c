/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Echo a string on the terminal
*/

#include "includes.h"

void                my_putstr_fd(const char *str, int fd)
{
    for (int i = 0; str[i]; i++)
        my_putchar_fd(str[i], fd);
}

void                my_putstr(const char *str)
{
    my_putstr_fd(str, 1);
}
