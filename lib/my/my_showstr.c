/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Show str (do not print non-printable chars)
*/

#include "includes.h"

void                my_showstr_fd(const char *str, int fd)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < 32 || str[i] > 126) {
            my_putchar_fd('\\', fd);
            my_putnbr_base_fd((int)str[i], "0123456789abcdef", fd);
        } else {
            my_putchar_fd(str[i], fd);
        }
    }
}

void                my_showstr(const char *str)
{
    my_showstr_fd(str, 1);
}
