/*
** EPITECH PROJECT, 2023
** FullLib
** File description:
** my_debug_functions_delta
*/

#include "../includes.h"

static void         dev_debug_print_long_long(long long int nbr, int fd)
{
    if (nbr < 0) {
        my_putchar_fd('-', fd);
        dev_debug_print_long_long(-nbr, fd);
        return;
    }
    if (nbr < 10) {
        my_putchar_fd(nbr + 48, fd);
        return;
    }
    dev_debug_print_long_long(nbr / 10, fd);
    my_putchar_fd(nbr % 10 + 48, fd);
}

void                debug_print_long_long(void *val, int fd)
{
    long long int i = *(long long int *)val;
    dev_debug_print_long_long(i, fd);
}

void                dev_debug_print_float(float val, int fd)
{
    if (val < 0) {
        my_putchar_fd('-', fd);
        dev_debug_print_float(-val, fd);
        return;
    }
    my_putnbr_fd((int)val, fd);
    my_putchar_fd('.', fd);
    val -= (float)(int)val;
    val *= 10;
    for (int i = 0; i < 6; i++) {
        my_putchar_fd((int)val + 48, fd);
        val -= (float)(int)val;
        val *= 10;
    }
}

void                debug_print_float(void *val, int fd)
{
    float f = *(float *)val;
    dev_debug_print_float(f, fd);
}
