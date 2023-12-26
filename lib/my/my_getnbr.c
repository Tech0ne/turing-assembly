/*
** EPITECH PROJECT, 2023
** lib
** File description:
** From str to int
*/

#include "includes.h"

int                 my_getnbr_raw(const char *str)
{
    if (!my_strlen(str))
        return -1;
    int sign = 1, i = 0, nb = 0;
    for (; (str[i] < '0' || str[i] > '9') && str[i] != '\0'; i++)
        if (str[i] == '-')
            sign *= -1;
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        if (nb == 2147483640 && str[i] > '7')
            return 0;
        nb += str[i] - 48;
        if (str[i + 1] < '0' || str[i + 1] > '9')
            return (nb * sign);
        if (nb > 214748364)
            return 0;
        nb *= 10;
    }
    return -1;
}

int                 my_getnbr(const char *str)
{
    if (!my_strlen(str))
        return -1;
    int sign = 1, i = 0, nb = 0;
    if (str[0] == '-') {
        sign = -1;
        i = 1;
    }
    if (!my_str_are_only(&str[i], "0123456789"))
        return -1;
    for (; str[i]; i++) {
        if (nb == 2147483640 && str[i] > '7')
            return 0;
        nb += str[i] - 48;
        if (!str[i + 1])
            return (nb * sign);
        if (nb > 214748364)
            return 0;
        nb *= 10;
    }
    return -1;
}

int                 my_get_unsigned_nbr(const char *str)
{
    if (!str)
        return 0;
    if (str[0] == '-')
        return -1;
    return my_getnbr(str);
}
