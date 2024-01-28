/*
** EPITECH PROJECT, 2023
** my
** File description:
** h_printf
*/

#ifndef INCLUDED_LIB_PRINTF_H
    #define INCLUDED_LIB_PRINTF_H

    #include <stdarg.h>
    #include <stdio.h>

//---------------------------------- SYNTAX -----------------------------------
// This reproduction of the printf function use a sytax which is a little
// different than the original one.
// The syntax is that :
// %type;formats%
// You can see that, first of all, formater need to start AND END with a %.
// This choice was made to allow more complex and deep formaters.
// The ";formats" is optional and define "behaviour modificators" for the base
// type show. They are comma separated
// For example, the object %s% will display a string, while the formater
// %s;r% will display it backward.
// A list of types and formaters can be found at the end of this file
//-----------------------------------------------------------------------------

/// @brief Here it is, the printf remake. It use another syntax, see h_printf.h
/// @param format The formater string. Syntax is described in h_printf.h
void                my_printf(char *format, ...);

/// @brief Printf into a file descriptor
/// @param fd Target file descriptor
/// @param format The formater string. Syntax is described in h_printf.h
void                my_fprintf(int fd, char *format, ...);

/// @brief Write out the output of this printf into a FILE pointer
/// @param ptr The target FILE pointer
/// @param format The formater string. Syntax is described in h_printf.h
void                my_file_printf(FILE *ptr, char *format, ...);

void                dev_printf_display_format(char *format, int *index,
    va_list args, int fd);

void                display_basic_object_alpha(va_list args,
    variable_type type, char *formater, int fd);
void                dev_printf_display_from_type(va_list args,
    variable_type type, char *formater, int fd);

// This was like a side quest. Re make the "hexyl" command.
// It works quite well, not gonna lie
// Simply past your string, past the strlen, and it shows you the color hexdump
// The fact that you need to specify the length comes from the fact that it can
// be used with binary files. Better not stop only when u get a 0 val on bin.
// But, of course, specifying a -1 as the length let u stop when u meet a 0
void                my_hexyl_fd(char *string, int length, int fd);
    #define my_hexyl(string, length) my_hexyl_fd(string, length, 1)
// End of the side quest

void                printf_print_uint(unsigned int i, char *formater, int fd);
void                printf_print_int(int i, char *formater, int fd);
void                printf_print_ulint(unsigned long int i, char *formater,
    int fd);
void                printf_print_lint(long int i, char *formater, int fd);
void                printf_print_ullint(unsigned long long int i,
    char *formater, int fd);
void                printf_print_llint(long long int i, char *formater,
    int fd);
void                printf_print_double(double d, char *formater, int fd);
void                printf_print_ldouble(long double d, char *formater,
    int fd);
void                printf_print_string(char *s, char *formater, int fd);
void                printf_print_pointer(void *p, char *formater, int fd);

//----------------------------------- LIST ------------------------------------
// ######## TYPES ########
// (default) means that the default "char", for example, is a signed char
// "uc" => unsigned char
// "c" => signed char (default)
// "usi" => unsigned short int
// "si" => signed short int (default)
// "ui" => unsigned int
// "i" => signed int (default)
// "uli" => unsigned long int
// "li" => signed long int (default)
// "ulli" => unsigned long long int (default)
// "lli" => signed long long int (default)
// "f" => float
// "d" => double
// "ld" => long double
// "s" => string
// "p" => pointer
// Note that if the input is not part of one of these, it will be casted as "p"
// You can also put any number of "*" at the begining of any of these to define
// pointers of these types :
// If I have an int ***, I can do :
//     my_printf("%***i%", my_int_p_p_p);
// To display the pointed int.
// ######## FORMATERS ########
// # For ints (any type, signed, unsigned, short, long long...)
// b:01234      => on base "01234"
// p            => also print a pointer
// u            => print version signed and unsigned (can be usefull for debug)
// f:XXX.XX     => print a certain ammount of elements before and after comma
// # For strings
// c:red        => Gimmi colors !(white, grey, blink, red, green, yellow, blue)
// r            => Write the string in reverse
// h            => hexyl
// # For pointers
// b:01234567   => on base 012345678
// h            => hexyl the first 16 bytes found when following that pointer
// ### PLEASE NOTE THAT THIS MAY SEGFAULT YOUR PROGRAM, PAY ATTENTION WHEN
// ### USING THIS !!!!
//-----------------------------------------------------------------------------

#endif
