/*
** EPITECH PROJECT, 2023
** FullLib
** File description:
** my_debug_functions_alpha
*/

#include "../includes.h"

void                debug_print_uchar(void *val, int fd)
{
    unsigned char c = *(unsigned char *)val;
    if (c < 32 || c > 126) {
        my_putstr_fd(MY_COLOR_RED, fd);
        my_putchar_fd('\\', fd);
        my_putnbr_base_fd((int)c, "0123456789abcdef", fd);
        my_putstr_fd(MY_COLOR_YELLOW, fd);
    } else {
        my_putchar_fd((char)c, fd);
    }
}

void                debug_print_char(void *val, int fd)
{
    char c = *(char *)val;
    if (c < 32 || c > 126) {
        my_putstr_fd(MY_COLOR_RED, fd);
        my_putchar_fd('\\', fd);
        my_putnbr_base_fd((int)c, "0123456789abcdef", fd);
        my_putstr_fd(MY_COLOR_YELLOW, fd);
    } else {
        my_putchar_fd(c, fd);
    }
}

void                debug_print_usint(void *val, int fd)
{
    unsigned short s = *(unsigned short *)val;
    my_putnbr_fd((int)s, fd);
}

void                debug_print_sint(void *val, int fd)
{
    short s = *(short *)val;
    my_putnbr_fd((int)s, fd);
}
