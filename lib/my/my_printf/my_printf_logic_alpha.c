/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_printf_logic_alpha
*/

#include "../includes.h"

variable_type       retreive_data_with_type_bravo(char *type)
{
    if (!my_strcmp(type, "uli")) {
        free(type); return VARIABLE_TYPE_UNSIGNED_LONG_INT;
    } if (!my_strcmp(type, "li")) {
        free(type); return VARIABLE_TYPE_SIGNED_LONG_INT;
    } if (!my_strcmp(type, "ulli")) {
        free(type); return VARIABLE_TYPE_UNSIGNED_LONG_LONG_INT;
    } if (!my_strcmp(type, "lli")) {
        free(type); return VARIABLE_TYPE_SIGNED_LONG_INT;
    } if (!my_strcmp(type, "f")) {
        free(type); return VARIABLE_TYPE_FLOAT;
    } if (!my_strcmp(type, "d")) {
        free(type); return VARIABLE_TYPE_DOUBLE;
    } if (!my_strcmp(type, "ld")) {
        free(type); return VARIABLE_TYPE_LONG_DOUBLE;
    } if (!my_strcmp(type, "s")) {
        free(type); return VARIABLE_TYPE_STRING;
    }
    free(type);
    return VARIABLE_TYPE_POINTER;
}

variable_type       retreive_data_with_type_alpha(char *format)
{
    char **splitted = my_str_split(format, ";");
    int index = 0; for (; splitted[0][index] == '*'; index++);
    char *type = my_strdup(&(splitted[0][index]));
    free_char_map(splitted);
    if (!my_strcmp(type, "uc")) {
        free(type); return VARIABLE_TYPE_UNSIGNED_CHAR;
    } if (!my_strcmp(type, "c")) {
        free(type); return VARIABLE_TYPE_SIGNED_CHAR;
    } if (!my_strcmp(type, "usi")) {
        free(type); return VARIABLE_TYPE_UNSIGNED_SHORT_INT;
    } if (!my_strcmp(type, "si")) {
        free(type); return VARIABLE_TYPE_SIGNED_SHORT_INT;
    } if (!my_strcmp(type, "ui")) {
        free(type); return VARIABLE_TYPE_UNSIGNED_INT;
    } if (!my_strcmp(type, "i")) {
        free(type); return VARIABLE_TYPE_SIGNED_INT;
    }
    return retreive_data_with_type_bravo(type);
}

void                display_basic_object_bravo(va_list args,
    variable_type type, char *formater, int fd)
{
    switch (type) {
        case VARIABLE_TYPE_UNSIGNED_LONG_LONG_INT:
            printf_print_ullint(va_arg(args, unsigned long long int), formater,
                fd); return;
        case VARIABLE_TYPE_SIGNED_LONG_LONG_INT:
            printf_print_llint(va_arg(args, long long int), formater, fd);
            return;
        case VARIABLE_TYPE_FLOAT:
            printf_print_double(va_arg(args, double), formater, fd); return;
        case VARIABLE_TYPE_DOUBLE:
            printf_print_double(va_arg(args, double), formater, fd); return;
        case VARIABLE_TYPE_LONG_DOUBLE:
            printf_print_ldouble(va_arg(args, double), formater, fd); return;
        case VARIABLE_TYPE_STRING:
            printf_print_string(va_arg(args, char *), formater, fd); return;
        default: break;
    }
    printf_print_pointer(va_arg(args, void *), formater, fd);
}

void                display_basic_object_alpha(va_list args,
    variable_type type, char *formater, int fd)
{
    switch (type) {case VARIABLE_TYPE_UNSIGNED_CHAR:
            printf_print_int(va_arg(args, int), formater, fd); return;
        case VARIABLE_TYPE_SIGNED_CHAR:
            printf_print_int(va_arg(args, int), formater, fd); return;
        case VARIABLE_TYPE_UNSIGNED_SHORT_INT:
            printf_print_int(va_arg(args, int), formater, fd); return;
        case VARIABLE_TYPE_SIGNED_SHORT_INT:
            printf_print_int(va_arg(args, int), formater, fd); return;
        case VARIABLE_TYPE_UNSIGNED_INT:
            printf_print_uint(va_arg(args, unsigned int), formater, fd); return;
        case VARIABLE_TYPE_SIGNED_INT:
            printf_print_int(va_arg(args, int), formater, fd); return;
        case VARIABLE_TYPE_UNSIGNED_LONG_INT:
            printf_print_ulint(va_arg(args, unsigned long int), formater, fd);
            return;
        case VARIABLE_TYPE_SIGNED_LONG_INT:
            printf_print_lint(va_arg(args, unsigned long int), formater, fd);
            return;
        default: break;
    } display_basic_object_bravo(args, type, formater, fd);
}

void                dev_printf_display_format(char *format, int *index,
    va_list args, int fd)
{
    *index += 1;
    if (my_str_get_index(&format[*index], '%') == -1) {
        *index = -1; return;
    } if (my_str_get_index(&format[*index], '%') == 0) {
        *index += 1; my_putchar_fd('%', fd); return;
    } char *formater = my_strndup(&format[*index],
        my_str_get_index(&format[*index], '%'));
    variable_type type = retreive_data_with_type_alpha(formater);
    dev_printf_display_from_type(args, type, formater, fd);
    *index += my_strlen(formater);
    free(formater);
}
