/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Echo a number on the terminal
*/

#include "includes.h"

void                my_putnbr_fd(int nbr, int fd)
{
    if (nbr < 0) {
        my_putchar_fd('-', fd);
        my_putnbr_fd(-nbr, fd);
        return;
    }
    if (nbr < 10) {
        my_putchar_fd(nbr + 48, fd);
        return;
    }
    my_putnbr_fd(nbr / 10, fd);
    my_putchar_fd(nbr % 10 + 48, fd);
}

void                my_putnbr(int nbr)
{
    my_putnbr_fd(nbr, 1);
}
