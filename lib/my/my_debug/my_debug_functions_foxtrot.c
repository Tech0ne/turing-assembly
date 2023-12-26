/*
** EPITECH PROJECT, 2023
** FullLib
** File description:
** my_debug_functions_echo
*/

#include "../includes.h"

static void         dev_debug_print_special_char(char c, int fd)
{
    switch (c) {
        case 0: my_putchar_fd('0', fd); return;
        case 7: my_putchar_fd('a', fd); return;
        case 8: my_putchar_fd('b', fd); return;
        case 9: my_putchar_fd('t', fd); return;
        case 10: my_putchar_fd('n', fd); return;
        case 11: my_putchar_fd('v', fd); return;
        case 12: my_putchar_fd('f', fd); return;
        case 13: my_putchar_fd('r', fd); return;
        default: break;
    }
    if (c >= 0 && c <= 16) my_putchar_fd('0', fd);
    my_putnbr_base_fd((int)c, "0123456789abcdef", fd);
}

void                debug_print_string(void *val, int fd)
{
    char *str = *(char **)val;
    if (!str) {
        my_putstr_fd("(nil)", fd);
        return;
    }
    my_putchar_fd('"', fd);
    for (int i = 0; str[i]; i++) {
        if (str[i] < 32 || str[i] > 126) {
            my_putstr_fd(MY_COLOR_RED, fd);
            my_putchar_fd('\\', fd);
            dev_debug_print_special_char(str[i], fd);
            my_putstr_fd(MY_COLOR_YELLOW, fd);
        } else {
            my_putchar_fd(str[i], fd);
        }
    }
    my_putchar_fd('"', fd);
}

void                debug_print_pointer(void *val, int fd)
{
    unsigned long long ptr = *(unsigned long long *)&val;
    my_putstr_fd("0x", fd);
    char *base = "0123456789abcdef";
    unsigned long long basenum = my_strlen(base);
    if (basenum == 0)
        return;
    unsigned long long rest = ptr;
    unsigned long long power = 1;
    while ((rest / power) > basenum)
        power *= basenum;
    while (power > 0) {
        my_putchar_fd(base[rest / power], fd);
        rest %= power;
        power /= basenum;
    }
}
