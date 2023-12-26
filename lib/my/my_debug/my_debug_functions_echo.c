/*
** EPITECH PROJECT, 2023
** FullLib
** File description:
** my_debug_functions_echo
*/

#include "../includes.h"

void                dev_debug_print_double(double val, int fd)
{
    if (val < 0) {
        my_putchar_fd('-', fd);
        dev_debug_print_double(-val, fd);
        return;
    }
    my_putnbr_fd((int)val, fd);
    my_putchar_fd('.', fd);
    val -= (double)(int)val;
    val *= 10;
    for (int i = 0; i < 6; i++) {
        my_putchar_fd((int)val + 48, fd);
        val -= (double)(int)val;
        val *= 10;
    }
}

void                debug_print_double(void *val, int fd)
{
    double d = *(double *)val;
    dev_debug_print_double(d, fd);
}

void                dev_debug_print_long_double(long double val, int fd)
{
    if (val < 0) {
        my_putchar_fd('-', fd);
        dev_debug_print_long_double(-val, fd);
        return;
    }
    my_putnbr_fd((int)val, fd);
    my_putchar_fd('.', fd);
    val -= (long double)(int)val;
    val *= 10;
    for (int i = 0; i < 6; i++) {
        my_putchar_fd((int)val + 48, fd);
        val -= (long double)(int)val;
        val *= 10;
    }
}

void                debug_print_long_double(void *val, int fd)
{
    float d = *(long double *)val;
    dev_debug_print_long_double(d, fd);
}
