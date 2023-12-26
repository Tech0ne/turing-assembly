/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Echo number within given base
*/

#include "includes.h"

void                my_putnbr_base_fd(int nbr, const char *base, int fd)
{
    if (nbr < 0) {
        my_putchar_fd('-', fd);
        my_putnbr_base_fd(-nbr, base, fd);
        return;
    }
    if (nbr < my_strlen(base)) {
        my_putchar_fd(base[nbr], fd);
        return;
    }
    my_putnbr_base_fd(nbr / my_strlen(base), base, fd);
    my_putchar_fd(base[nbr % my_strlen(base)], fd);
}

void                my_putnbr_base(int nbr, const char *base)
{
    my_putnbr_base_fd(nbr, base, 1);
}
