/*
** EPITECH PROJECT, 2023
** FullLib
** File description:
** my_debug_functions_charlie
*/

#include "../includes.h"

void                dev_debug_print_long(long int nbr, int fd)
{
    if (nbr < 0) {
        my_putchar_fd('-', fd);
        dev_debug_print_long(-nbr, fd);
        return;
    }
    if (nbr < 10) {
        my_putchar_fd(nbr + 48, fd);
        return;
    }
    dev_debug_print_long(nbr / 10, fd);
    my_putchar_fd(nbr % 10 + 48, fd);
}

void                debug_print_long(void *val, int fd)
{
    long int i = *(long int *)val;
    dev_debug_print_long(i, fd);
}

void                dev_debug_ulong_long(unsigned long long int nbr, int fd)
{
    if (nbr < 10) {
        my_putchar_fd(nbr + 48, fd);
        return;
    }
    dev_debug_ulong_long(nbr / 10, fd);
    my_putchar_fd(nbr % 10 + 48, fd);
}

void                debug_print_ulong_long(void *val, int fd)
{
    unsigned long long int i = *(unsigned long long int *)val;
    dev_debug_ulong_long(i, fd);
}
