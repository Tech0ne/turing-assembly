/*
** EPITECH PROJECT, 2023
** MyPrintf
** File description:
** my_printf_logic.bravo
*/

#include "../includes.h"

void                display_pointed_object_bravo(void *obj, char *formater,
    variable_type type, int fd)
{
    switch (type) {
        case VARIABLE_TYPE_UNSIGNED_LONG_LONG_INT:
            printf_print_ullint(*(unsigned long long int *)obj, formater,
                fd); return;
        case VARIABLE_TYPE_SIGNED_LONG_LONG_INT:
            printf_print_llint(*(long long int *)obj, formater, fd);
            return;
        case VARIABLE_TYPE_FLOAT:
            printf_print_double(*(double *)obj, formater, fd); return;
        case VARIABLE_TYPE_DOUBLE:
            printf_print_double(*(double *)obj, formater, fd); return;
        case VARIABLE_TYPE_LONG_DOUBLE:
            printf_print_ldouble(*(double *)obj, formater, fd); return;
        case VARIABLE_TYPE_STRING:
            printf_print_string(*(char **)obj, formater, fd); return;
        default: break;
    }
    printf_print_pointer(obj, formater, fd);
}

void                display_pointed_object_alpha(void *obj, char *formater,
    variable_type type, int fd)
{
    switch (type) {case VARIABLE_TYPE_UNSIGNED_CHAR:
            printf_print_int(*(int *)obj, formater, fd); return;
        case VARIABLE_TYPE_SIGNED_CHAR:
            printf_print_int(*(int *)obj, formater, fd); return;
        case VARIABLE_TYPE_UNSIGNED_SHORT_INT:
            printf_print_int(*(int *)obj, formater, fd); return;
        case VARIABLE_TYPE_SIGNED_SHORT_INT:
            printf_print_int(*(int *)obj, formater, fd); return;
        case VARIABLE_TYPE_UNSIGNED_INT:
            printf_print_uint(*(unsigned int *)obj, formater, fd); return;
        case VARIABLE_TYPE_SIGNED_INT:
            printf_print_int(*(int *)obj, formater, fd); return;
        case VARIABLE_TYPE_UNSIGNED_LONG_INT:
            printf_print_ulint(*(unsigned long int *)obj, formater, fd);
            return;
        case VARIABLE_TYPE_SIGNED_LONG_INT:
            printf_print_lint(*(long int *)obj, formater, fd); return;
        default: break;
    } display_pointed_object_bravo(obj, formater, type, fd);
}

void                dev_printf_display_from_type(va_list args,
    variable_type type, char *formater, int fd)
{
    if (formater[0] != '*') {
        display_basic_object_alpha(args, type, formater, fd); return;
    } void *obj = va_arg(args, void *);
    int nb_decals = 0;
    for (; formater[nb_decals] == '*'; nb_decals++);
    nb_decals--;
    for (int i = 0; i < nb_decals; i++) obj = *(void **)obj;
    display_pointed_object_alpha(obj, formater, type, fd);
}
