/*
** EPITECH PROJECT, 2023
** FullLib
** File description:
** h_debug
*/

#ifndef INCLUDED_LIB_DEBUG_H
    #define INCLUDED_LIB_DEBUG_H

void                debug_print_uchar(void *val, int fd);
void                debug_print_char(void *val, int fd);
void                debug_print_usint(void *val, int fd);
void                debug_print_sint(void *val, int fd);
void                debug_print_uint(void *val, int fd);
void                debug_print_int(void *val, int fd);
void                debug_print_ulong(void *val, int fd);
void                debug_print_long(void *val, int fd);
void                debug_print_ulong_long(void *val, int fd);
void                debug_print_long_long(void *val, int fd);
void                debug_print_float(void *val, int fd);
void                debug_print_double(void *val, int fd);
void                debug_print_long_double(void *val, int fd);
void                debug_print_string(void *val, int fd);
void                debug_print_pointer(void *val, int fd);

#endif
