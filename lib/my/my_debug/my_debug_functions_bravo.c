/*
** EPITECH PROJECT, 2023
** FullLib
** File description:
** my_debug_functions_bravo
*/

#include "../includes.h"

void                dev_debug_print_uint(unsigned int nbr, int fd)
{
    if (nbr < 10) {
        my_putchar_fd(nbr + 48, fd);
        return;
    }
    dev_debug_print_uint(nbr / 10, fd);
    my_putchar_fd(nbr % 10 + 48, fd);
}

void                debug_print_uint(void *val, int fd)
{
    unsigned int i = *(unsigned int *)val;
    dev_debug_print_uint(i, fd);
}

void                debug_print_int(void *val, int fd)
{
    my_putnbr_fd(*(int *)val, fd);
}

void                dev_debug_print_ulong(unsigned long int nbr, int fd)
{
    if (nbr < 10) {
        my_putchar_fd(nbr + 48, fd);
        return;
    }
    dev_debug_print_ulong(nbr / 10, fd);
    my_putchar_fd(nbr % 10 + 48, fd);
}

void                debug_print_ulong(void *val, int fd)
{
    unsigned long int i = *(unsigned long int *)val;
    dev_debug_print_ulong(i, fd);
}
