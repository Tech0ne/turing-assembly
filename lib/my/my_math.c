/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Math pow function
*/

#include "includes.h"

int                 my_pow(int x, int power)
{
    if (power < 0) return 0;
    if (power == 0) return 1;

    return x * my_pow(x, power - 1);
}

bool                my_is_prime(int nb)
{
    if (nb <= 2) return true;

    for (int i = 2; i < nb; i++)
        if (!(nb % i))
            return false;

    return true;
}
