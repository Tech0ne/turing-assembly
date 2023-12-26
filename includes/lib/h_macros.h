/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Some important defines macros (including function overwriting)
*/

#ifndef INCLUDED_LIB_DEFINES_H
    #define INCLUDED_LIB_DEFINES_H

    #include "includes.h"

    #define STR(obj) #obj
    #define POINTER(obj) &obj

    // ####################### Colors #######################

    #define MY_COLOR_RESET "\33[0m"
    #define MY_COLOR_GREY "\33[90m"
    #define MY_COLOR_BLINK "\33[5m"
    #define MY_COLOR_RED "\33[91m"
    #define MY_COLOR_GREEN "\33[92m"
    #define MY_COLOR_YELLOW "\33[93m"
    #define MY_COLOR_BLUE "\33[94m"

    // ####################### Structs #######################

    #define m_box _m_box *

    // ####################### Functions #######################

    #define typeof(x) _Generic((x),                                     \
        unsigned char : VARIABLE_TYPE_UNSIGNED_CHAR,                    \
        char : VARIABLE_TYPE_SIGNED_CHAR,                               \
        unsigned short int : VARIABLE_TYPE_UNSIGNED_SHORT_INT,          \
        short int : VARIABLE_TYPE_SIGNED_SHORT_INT,                     \
        unsigned int : VARIABLE_TYPE_UNSIGNED_INT,                      \
        int : VARIABLE_TYPE_SIGNED_INT,                                 \
        unsigned long int : VARIABLE_TYPE_UNSIGNED_LONG_INT,            \
        long int : VARIABLE_TYPE_SIGNED_LONG_INT,                       \
        unsigned long long int : VARIABLE_TYPE_UNSIGNED_LONG_LONG_INT,  \
        long long int : VARIABLE_TYPE_SIGNED_LONG_LONG_INT,             \
        float : VARIABLE_TYPE_FLOAT,                                    \
        double : VARIABLE_TYPE_DOUBLE,                                  \
        long double : VARIABLE_TYPE_LONG_DOUBLE,                        \
        char * : VARIABLE_TYPE_STRING,                                  \
        default: VARIABLE_TYPE_POINTER)

    #define my_debug(var) dev_my_debug(my_create_box(STR(var),\
        POINTER(var), typeof(var), sizeof(var)), __LINE__, __FILE__)
    #define my_debug_custom(var, func) dev_my_debug_custom(\
        my_create_box(STR(var), POINTER(var), typeof(var), sizeof(var)), __LINE__, __FILE__,\
            func)
    #define hexyl(my_box) my_hexyl_fd()

#endif
