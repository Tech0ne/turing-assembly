/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Sample color outputs
*/

#include "includes.h"

void                my_putstr_color_fd(char *str, char *color, int fd)
{
    my_putstr_fd(MY_COLOR_RESET, fd);
    my_putstr_fd(color, fd);
    my_putstr_fd(str, fd);
    my_putstr_fd(MY_COLOR_RESET, fd);
}

void                my_putstr_color(char *str, char *color)
{
    my_putstr_color_fd(str, color, 1);
}
