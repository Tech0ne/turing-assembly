/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_printf_functions_bravo
*/

#include "../includes.h"

void                printf_print_ullint(unsigned long long int i,
    char *formater, int fd)
{
    debug_print_ulong_long((void *)&i, fd);
}

void                printf_print_llint(long long int i, char *formater, int fd)
{
    debug_print_long_long((void *)&i, fd);
}

void                printf_print_double(double d, char *formater, int fd)
{
    debug_print_double((void *)&d, fd);
}

void                printf_print_ldouble(long double d, char *formater, int fd)
{
    debug_print_long_double((void *)&d, fd);
}
