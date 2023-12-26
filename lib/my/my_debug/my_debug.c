/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_debug
*/

#include "../includes.h"

void              (*get_debug_function(variable_type type))(void *value,
    int fd) {
    if (type == VARIABLE_TYPE_UNSIGNED_CHAR) return &debug_print_uchar;
    if (type == VARIABLE_TYPE_SIGNED_CHAR) return &debug_print_char;
    if (type == VARIABLE_TYPE_UNSIGNED_SHORT_INT) return &debug_print_usint;
    if (type == VARIABLE_TYPE_SIGNED_SHORT_INT) return &debug_print_sint;
    if (type == VARIABLE_TYPE_UNSIGNED_INT) return &debug_print_uint;
    if (type == VARIABLE_TYPE_SIGNED_INT) return &debug_print_int;
    if (type == VARIABLE_TYPE_UNSIGNED_LONG_INT) return &debug_print_ulong;
    if (type == VARIABLE_TYPE_SIGNED_LONG_INT) return &debug_print_long;
    if (type == VARIABLE_TYPE_UNSIGNED_LONG_LONG_INT)
        return &debug_print_ulong_long;
    if (type == VARIABLE_TYPE_SIGNED_LONG_LONG_INT)
        return &debug_print_long_long;
    if (type == VARIABLE_TYPE_FLOAT) return &debug_print_float;
    if (type == VARIABLE_TYPE_DOUBLE) return &debug_print_double;
    if (type == VARIABLE_TYPE_LONG_DOUBLE) return &debug_print_long_double;
    if (type == VARIABLE_TYPE_STRING) return &debug_print_string;
    if (type == VARIABLE_TYPE_POINTER) return &debug_print_pointer;
    return NULL;
}

static void         show_value(variable_type type, void *value)
{
    my_putstr(MY_COLOR_YELLOW);
    get_debug_function(type)(value, 1);
    my_putchar('\n');
    my_putstr(MY_COLOR_RESET);
}

void                dev_my_debug(m_box var, int line, char *file)
{
    my_putstr(MY_COLOR_GREY);
    my_putstr(file);
    my_putstr(":");
    my_putnbr(line);
    my_putstr(": ");
    my_putstr_color(var->name, MY_COLOR_GREEN);
    my_putstr_color(": ", MY_COLOR_GREY);
    show_value(var->type, var->value);
    my_delet_box(var);
}

void                dev_my_debug_custom(m_box var, int line,
    char *file, void (*func)(void *))
{
    my_putstr(MY_COLOR_GREY);
    my_putstr(file);
    my_putstr(":");
    my_putnbr(line);
    my_putstr(": ");
    my_putstr_color(var->name, MY_COLOR_GREEN);
    my_putstr_color(": ", MY_COLOR_GREY);
    func(var->value);
    my_delet_box(var);
}
