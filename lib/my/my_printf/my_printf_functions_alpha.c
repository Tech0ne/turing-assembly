/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_printf_functions_alpha
*/

#include "../includes.h"

void                my_putuint_formated(unsigned int u, char *base, char *format,
    int fd)
{
    if (!my_strlen(base)) {
        my_putnbr_fd(u, fd); return;
    } int basenum = my_strlen(base);
    int nb_bfore = 0, nb_after = 0;
    for (; format[nb_bfore] == 'X'; nb_bfore++);
    if (format[nb_bfore] == '.')
        for (; format[nb_bfore + nb_after + 1] == 'X'; nb_after++);
    for (int i = 0; i < nb_bfore; i++) {
        my_putchar_fd(base[u % basenum], fd);
        u /= basenum;
    }
    if (my_str_get_index(format, '.') == -1) return;
    my_putchar_fd('.', fd);
    for (int i = 0; i < nb_after; i++)
        my_putchar_fd('0', fd);
}

void                printf_print_uint(unsigned int u, char *formater, int fd)
{
    if (my_str_get_index(formater, ';') == -1) {
        debug_print_uint((void *)&u, fd); return;
    } char **formats = my_str_split(&formater[my_str_get_index(formater, ';')
        + 1], ","); for (int i = 0; formats[i]; i++) {
        if (my_strcmp(formats[i], "p") == 0) {
            printf_print_pointer((void *)&u, "p", fd); my_putstr(" => ");
        }
    } char *base = NULL; for (int i = 0; formats[i]; i++) {
        if (my_strcmp(formats[i], "u") == 0) {
            debug_print_int((void *)&u, fd); my_putstr_fd(" - ", fd);
        } if (my_strncmp(formats[i], "b:", 2) == 0) {
            base = my_strdup(&(formats[i][2]));
        }
    } if (!base) {base = my_strdup("0123456789");
    } for (int i = 0; formats[i]; i++) {
        if (my_strncmp(formats[i], "f:", 2) == 0) {
            my_putuint_formated(u, base, &(formats[i][2]), fd);
            free_char_map(formats); free(base); return;
        }
    } debug_print_uint((void *)&u, fd); free_char_map(formats); free(base);
}

void                my_putint_formated(int i, char *base, char *format, int fd)
{
    if (!my_strlen(base)) {
        my_putnbr_fd(i, fd); return;
    } int basenum = my_strlen(base);
    int nb_bfore = 0, nb_after = 0;
    for (; format[nb_bfore] == 'X'; nb_bfore++);
    if (format[nb_bfore] == '.')
        for (; format[nb_bfore + nb_after + 1] == 'X'; nb_after++);
    if (i < 0) {
        my_putchar_fd('-', fd);
        my_putint_formated(-i, base, format, fd);
        return;
    }
    for (int in = 0; in < nb_bfore; in++) {
        my_putchar_fd(base[i % basenum], fd);
        i /= basenum;
    }
    if (my_str_get_index(format, '.') == -1) return;
    my_putchar_fd('.', fd);
    for (int in = 0; in < nb_after; in++)
        my_putchar_fd('0', fd);
}

void                printf_print_int(int i, char *formater, int fd)
{
    if (my_str_get_index(formater, ';') == -1) {
        my_putnbr_fd(i, fd); return;
    } char **formats = my_str_split(&formater[my_str_get_index(formater, ';')
        + 1], ","); for (int in = 0; formats[in]; in++) {
        if (my_strcmp(formats[in], "p") == 0) {
            printf_print_pointer((void *)&i, "p", fd); my_putstr(" => ");
        }
    } char *base = NULL; for (int in = 0; formats[in]; in++) {
        if (my_strcmp(formats[in], "u") == 0) {
            debug_print_uint((void *)&i, fd); my_putstr_fd(" - ", fd);
        } if (my_strncmp(formats[in], "b:", 2) == 0) {
            base = my_strdup(&(formats[in][2]));
        }
    } if (!base) {base = my_strdup("0123456789");
    } for (int in = 0; formats[in]; in++) {
        if (my_strncmp(formats[in], "f:", 2) == 0) {
            my_putint_formated(i, base, &(formats[in][2]), fd);
            free_char_map(formats); free(base); return;
        }
    } my_putnbr_base_fd(i, base, fd); free_char_map(formats); free(base);
}

void                printf_print_ulint(unsigned long int i, char *formater,
    int fd)
{
    debug_print_ulong((void *)&i, fd);
}

void                printf_print_lint(long int i, char *formater, int fd)
{
    debug_print_long((void *)&i, fd);
}
