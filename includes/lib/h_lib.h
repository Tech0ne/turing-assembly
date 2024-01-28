/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Main lib file (prototyping all functions)
*/

#ifndef INCLUDED_LIB_LIB_H
    #define INCLUDED_LIB_LIB_H

    #include "includes.h"

//====================== my_box.c ======================

/// @brief Create a "box": struct with a name, a value and a type
/// @param name The box name : str
/// @param value The box value : any type pointer
/// @param type The box type : variable_type
/// @return The newly created box
m_box               my_create_box(char *name, void *value, variable_type type, unsigned long size);

/// @brief Delete a box
/// @param box The box to delete
void                my_delet_box(m_box box);

//====================== my_colors.c ======================

/// @brief Write out data to a file descriptor with colors
/// @param str The str to write out
/// @param color The color to use
/// @param fd Output file descriptor
void                my_putstr_color_fd(char *str, char *color, int fd);

/// @brief Same as my_putstr_color_fd, but on STDOUT
/// @param str The string to be shown
/// @param color The color to display the string
void                my_putstr_color(char *str, char *color);

//====================== my_frees.c ======================

/// @brief Completly free a char map
/// @param map The map to be freed
void                free_char_map(char **map);

/// @brief Completly free a int map
/// @param map The map to be freed
void                free_int_map(int **map);

//====================== my_debug_functions.c ======================

/// @brief Write out a float number on screen
/// @param nbr The actual number to be displayed
/// @param nb_round The nb to show after the dot
void                my_putfloat(float nbr, int nb_round);

/// @brief Write out a double on screen
/// @param nbr The actual double to be printed
/// @param nb_round The nb to show after the dot
void                my_putdouble(double nbr, int nb_round);

/// @brief Write out a long double on screen
/// @param nbr The actual long double to be shown
/// @param nb_round The nb to show after the dot
void                my_putldouble(long double nbr, int nb_round);

/// @brief Display a looong int to the screen
/// @param nbr The actual looong int
void                my_putlnbr(long long int nbr);

//====================== my_debug.c ======================

/// @brief Use my_debug macro -> Debug a variable by its type
/// @param var The variable (as a box)
/// @param line The actual line where it's used
/// @param file The actual file where it's used
void                dev_my_debug(m_box var, int line, char *file);

/// @brief Use my_debug_custom macro -> Debug a custom type of variable
/// @param var The variable (as a box)
/// @param line The actual line where it's used
/// @param file The actual file where it's used
/// @param func The function executed to show the variable content
void                dev_my_debug_custom(m_box var, int line,
    char *file, void (*func)(void *));

//====================== my_getnbr.c ======================

/// @brief Get a signed number from a string (even with sh*t before)
/// @param str The actual string to cast as int
/// @return The int writen on 'str'
int                 my_getnbr_raw(const char *str);

/// @brief Get a signed number from a string (if it's not a number, throws -1)
/// @param str The actual string to cast as int
/// @return The int writen on 'str', or -1 if error
int                 my_getnbr(const char *str);

/// @brief Get an unsigned number from a string (-1 if error)
/// @param str The actual string to cast as int
/// @return The unsigned int writen on 'str', or -1 if error
int                 my_get_unsigned_nbr(const char *str);

//====================== my_math.c ======================

/// @brief Return 'x' pow 'power'
/// @param x Number to put pow 'power'
/// @param power The actual power
/// @return The calculated final value
int                 my_pow(int x, int power);

/// @brief Return true if 'nb' is prime and false else
/// @param nb The number to check for prime
/// @return true if 'nb' is prime, else false
bool                my_is_prime(int nb);

//====================== my_memory.c ======================

/// @brief Fill in a buffer with a defined byte value
/// @param buff The target buffer
/// @param c The byte value to fill in the buffer
/// @param size The buffer size
void                my_memset(byte *buff, byte c, unsigned long size);

/// @brief Equivalent to realloc, "re malloc" the buffer, adding 'size' bytes
/// @param buffer The original buffer to be copied and resized
/// @param size The aditional size
/// @param was_malloced true if 'buffer' was malloced, else false
/// @return The new buffer resized and re filled
char               *my_add_size(byte *buffer, int size, bool was_malloced);

//====================== my_putchar.c ======================

/// @brief Write a byte into a file descriptor
/// @param c The actual byte to write into the file descriptor
/// @param fd The file descriptor to write
void                my_putchar_fd(byte c, int fd);

/// @brief Write a char in STDOUT
/// @param c The char to write
void                my_putchar(char c);

//====================== my_putnbr_base.c ======================

/// @brief Write out a number into a file descriptor, transcripted into 'base'
/// @param nbr The number to be writen
/// @param base The base, as a char array
/// @param fd The target file descriptor
void                my_putnbr_base_fd(int nbr, const char *base, int fd);

/// @brief Write out a number into STDOUT
/// @param nbr The number to be shown
/// @param base The base, as a char array
void                my_putnbr_base(int nbr, const char *base);

//====================== my_putnbr.c ======================

/// @brief Write out a number into a file descriptor
/// @param nbr The actual number to be writen
/// @param fd The target file descriptor
void                my_putnbr_fd(int nbr, int fd);

/// @brief Write out a number into STDOUT
/// @param nbr The actual number to be writen
void                my_putnbr(int nbr);

//====================== my_putstr.c ======================

/// @brief Write out a string into a file descriptor
/// @param str The actual string
/// @param fd The file descriptor
void                my_putstr_fd(const char *str, int fd);

/// @brief Write out a string into STDOUT
/// @param str The actual string
void                my_putstr(const char *str);

//====================== my_revstr.c ======================

/// @brief Return a reversed string (malloced)
/// @param str The string to reverse
/// @return The reversed string
char               *my_revstr(char *str);

//====================== my_showstr.c ======================

/// @brief Write out a string (escaping special chars) into a file descriptor
/// @param str The base string
/// @param fd The target file descriptor
void                my_showstr_fd(const char *str, int fd);

/// @brief Write out a string (escaping special chars) into STDOUT
/// @param str The base string
void                my_showstr(const char *str);

//====================== my_str_are_in.c ======================

/// @brief Get the index of the first occurence of 'c' into 'str'
/// @param str The string to check
/// @param c The char to check
/// @return The index of the first occurence of 'c' in 'str', or -1
int                 my_str_get_index(const char *str, char c);

/// @brief Check if 'str' is only composed by chars that are in 'ref'
/// @param str The string to be checked
/// @param ref The reference string, containing all authorised chars
/// @return true if 'str' only contains chars from 'ref', else false
bool                my_str_are_only(const char *str, const char *ref);

//====================== my_str_capitalize.c ======================

/// @brief Capitalise a string, Every First Letter Of A Word Become Uppercase
/// @param str The string to change
/// @return 'str', that have been capitalized
char               *my_strcapitalize(char *str);

//====================== my_str_checks.c ======================

/// @brief Check if a string is only letters
/// @param str The string to check
/// @return true if 'str' only contains letters, else false
bool                my_str_is_letters(const char *str);

/// @brief Check if a string only contains numbers
/// @param str The string to check
/// @return true if 'str' is only made of numbers, else false
bool                my_str_is_numbers(const char *str);

/// @brief Check if 'str' do NOT contains lower case letters
/// @param str The string to check
/// @return true if none of the letters in 'str' where lowercase letters
bool                my_str_is_upper(const char *str);

/// @brief Check if 'str' do NOT contains upper case letters
/// @param str The string to check
/// @return true if none of the letters in 'str' where uppercase letters
bool                my_str_is_lower(const char *str);

//====================== my_str_count.c ======================

/// @brief Counts the number of 'c' in 'str'
/// @param str The string to check
/// @param c The char to be counted
/// @return The number of 'c' in 'str'
int                 my_str_count(const char *str, char c);

/// @brief Count the number of occurence of 'sub' in 'str' (sub is a string)
/// @param str The string to be checked
/// @param sub The substring to be counted
/// @return THe number of 'sub' in 'str'
int                 my_str_counts(const char *str, const char *sub);

//====================== my_str_find.c ======================

/// @brief Find 'sub' in 'str'. Return the index found, or -1
/// @param str The string to be scaned
/// @param sub The sub string to be searched
/// @return The index of the first occurence of 'sub' in 'str', or -1
int                 my_str_find(char *str, const char *sub);

//====================== my_str_join.c ======================

/// @brief Join a char ** into a char *, by filling spaces with 'join'
/// @param map The char map to be joined
/// @param join The join to be set between all parts of 'map'
/// @return The joined map, into a char *
char               *my_str_join(char **map, const char *join);

//====================== my_str_replace.c ======================

/// @brief Replace, in 'str', all 'sep' by 'to'
/// @param str The string to be replaced
/// @param sep The separator to be modified
/// @param to The next value of 'sep'
/// @return A NEW string containing the replaced one
char               *my_str_replace(char *str, char *sep, char *to);

//====================== my_str_split.c ======================

/// @brief Split up a string into a char ** at each 'sub'
/// @param str The original string to be splited
/// @param sub The spliter
/// @return The new map, splited every 'sub'
char              **my_str_split(char *str, const char *sub);

//====================== my_strcat.c ======================

/// @brief Concatenate 'src' in 'dest' (might segfault if dest is too small)
/// @param dest The target string
/// @param src The string to be copied into 'dest'
/// @return 'dest', modified
char               *my_strcat(char *dest, const char *src);

/// @brief Concatenate 'n' bytes of 'src' into 'dest' ( /!\ to segfaults )
/// @param dest The target string
/// @param src The string to be copied into 'dest'
/// @param n The number of bytes to be copied
/// @return 'dest', modified
char               *my_strncat(char *dest, const char *src, int n);

//====================== my_strcmp.c ======================

/// @brief Compare, byte by byte, 's1' and 's2'
/// @param s1 First string to compare
/// @param s2 Second string to compare
/// @return 0 if s1 is equal to s2, else, the difference between first != chars
int                 my_strcmp(const char *s1, const char *s2);

/// @brief Compare, byte by byte, 's1' and 's2' for 'n' bytes
/// @param s1 First string to compare
/// @param s2 Second string to compare
/// @param n The number of chars to compare
/// @return 0 if s1 is equal to s2, else, the difference between first != chars
int                 my_strncmp(const char *s1, const char *s2, int n);

//====================== my_strcpy.c ======================

/// @brief Copy 'src' into 'dest'
/// @param dest The target string
/// @param src The original string
/// @return Modified 'dest'
char               *my_strcpy(char *dest, const char *src);

/// @brief Copy 'n' bytes of 'str' into 'dest'
/// @param dest The target string
/// @param src The original string
/// @param n The number of bytes to copy
/// @return Modified 'dest'
char               *my_strncpy(char *dest, const char *src, int n);

//====================== my_strdup.c ======================

/// @brief Duplicate 'str' into a new buffer
/// @param str The original string
/// @return A copy of 'str'
char               *my_strdup(const char *str);

/// @brief Duplicate 'n' bytes of 'str' into a new buffer
/// @param str The original string
/// @param n The number of bytes to dup
/// @return A copy of 'n' bytes of 'str'
char               *my_strndup(const char *str, int n);

//====================== my_strlen.c ======================

/// @brief Get the length of a string
/// @param str The target string
/// @return The length of 'str'
int                 my_strlen(const char *str);

/// @brief Get the length of a sring up to a specific char
/// @param str The target string
/// @param c The char to check
/// @return The length of 'str' up to 'c', or to the end
int                 my_strlen_to_char(const char *str, char c);

//====================== my_swap.c ======================

/// @brief Swap the addresses of the two variables
/// @param a The first pointer
/// @param b The second pointer
void                my_swap(void *a, void *b);

#endif
