/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_printf
*/

#include "../includes.h"

#include <stdio.h>

void                my_printf(char *format, ...)
{
    va_list args;
    va_start(args, format);
    for (int i = 0; format[i]; i++) {
        if (format[i] != '%')
            my_putchar(format[i]);
        else
            dev_printf_display_format(format, &i, args, STDOUT_FILENO);
        if (i == -1) {
            my_putstr("Error !"); break;
        }
    }
    va_end(args);
}

void                my_fprintf(int fd, char *format, ...)
{
    va_list args;
    va_start(args, format);
    for (int i = 0; format[i]; i++) {
        if (format[i] != '%')
            my_putchar_fd(format[i], fd);
        else
            dev_printf_display_format(format, &i, args, fd);
        if (i == -1) {
            my_putstr_fd("Error !", fd); break;
        }
    }
    va_end(args);
}

void                my_file_printf(FILE *ptr, char *format, ...)
{
    int fd = ptr->_fileno;
    va_list args;
    va_start(args, format);
    for (int i = 0; format[i]; i++) {
        if (format[i] != '%')
            my_putchar_fd(format[i], fd);
        else
            dev_printf_display_format(format, &i, args, fd);
        if (i == -1) {
            my_putstr_fd("Error !", fd); break;
        }
    }
    va_end(args);
}
