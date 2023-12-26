/*
 * Hello world
 */

#include "includes.h"

int my_getnbr_base(const char *str, const char *base)
{
    if (!my_strlen(str))
        return -1;
    int i = 0, nb = 0;
    if (!my_str_are_only(str, base)) return -1;
    for (; str[i]; i++) {
        nb += my_str_get_index(base, str[i]);
        if (!str[i + 1])
            return (nb);
        nb *= my_strlen(base);
    }
    return -1;
}