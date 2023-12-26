/*
** EPITECH PROJECT, 2023
** MyPrintf
** File description:
** my_printf_functions_charlie
*/

#include "../includes.h"

void                printf_color_string(char *s, char *color)
{
    if (my_strcmp(color, "white") == 0) my_putstr(MY_COLOR_RESET);
    if (my_strcmp(color, "grey") == 0) my_putstr(MY_COLOR_GREY);
    if (my_strcmp(color, "blink") == 0) my_putstr(MY_COLOR_BLINK);
    if (my_strcmp(color, "red") == 0) my_putstr(MY_COLOR_RED);
    if (my_strcmp(color, "green") == 0) my_putstr(MY_COLOR_GREEN);
    if (my_strcmp(color, "yellow") == 0) my_putstr(MY_COLOR_YELLOW);
    if (my_strcmp(color, "blue") == 0) my_putstr(MY_COLOR_BLUE);
    my_putstr(s); free(s); my_putstr(MY_COLOR_RESET);
}

void                printf_print_string(char *s, char *formater, int fd)
{
    if (my_str_get_index(formater, ';') == -1) {
        my_putstr_fd(s, fd); return;
    } char **formats = my_str_split(&formater[my_str_get_index(formater, ';')
        + 1], ","); char *t = NULL;
    for (int i = 0; formats[i]; i++) {
        if (my_strcmp(formats[i], "r") == 0) {
            t = my_revstr(s);
        }
    } if (!t) {t = my_strdup(s);
    } for (int i = 0; formats[i]; i++) {
        if (formats[i][0] == 'h' && my_strlen(formats[i]) == 1) {
            my_hexyl_fd(t, my_strlen(t), fd); free(t); free_char_map(formats);
            return;
        }
    } int index = -1;
    for (int i = 0; formats[i]; i++)
        if (my_strncmp(formats[i], "c:", 2) == 0) {index = i;
    } if (fd != 1 || index == -1) {
        my_putstr_fd(t, fd); free_char_map(formats); free(t); return;
    } printf_color_string(t, &(formats[index][2])); free_char_map(formats);
}

static void         printf_print_actual_pointer(unsigned long long obj,
    char *base, int fd)
{
    unsigned long long basenum = my_strlen(base);
    if (basenum == 0)
        return;
    my_putstr("0x");
    unsigned long long rest = obj;
    unsigned long long power = 1;
    while ((rest / power) > basenum)
        power *= basenum;
    while (power > 0) {
        my_putchar_fd(base[rest / power], fd);
        rest %= power;
        power /= basenum;
    }
    if (my_strcmp(base, "0123456789abcdef") != 0) {
        my_putchar_fd('/', fd);
        debug_print_ulong_long(&basenum, fd);
    }
}

void                printf_print_pointer(void *p, char *formater, int fd)
{
    if (my_str_get_index(formater, ';') == -1) {
        debug_print_pointer(p, fd); return;
    } unsigned long long ptr = *(unsigned long long *)&p;
    char **formats = my_str_split(&formater[my_str_get_index(formater,
        ';') + 1], ",");
    for (int i = 0; formats[i]; i++) {
        if (my_strcmp(formats[i], "h") == 0) {
            my_hexyl_fd((char *)p, 16, fd);
            free_char_map(formats); return;
        }
    }
    char *base = NULL;
    for (int i = 0; formats[i]; i++) {
        if (my_strncmp(formats[i], "b:", 2) == 0) {
            base = my_strdup(&(formats[i][2])); break;
        }
    }
    if (!base) base = my_strdup("0123456789abcdef");
    printf_print_actual_pointer(ptr, base, fd);
    free(base); free_char_map(formats);
}
