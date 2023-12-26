/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Echo a char on the STDOUT / on the given fd
*/

#include "includes.h"

void                my_putchar_fd(byte c, int fd)
{
    write(fd, &c, 1);
}

void                my_putchar(char c)
{
    my_putchar_fd(c, 1);
}
