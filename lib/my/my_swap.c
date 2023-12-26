/*
** EPITECH PROJECT, 2023
** lib
** File description:
** swap two ints
*/

#include "includes.h"

void                my_swap(void *a, void *b)
{
    void *c = a;
    a = b;
    b = c;
}
