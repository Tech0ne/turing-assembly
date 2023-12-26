/*
 * Hello world
 */

#include "includes.h"

int my_list_length(m_list liste)
{
    m_list current = liste;
    int i = 0;
    for (; current; current = current->next) i++;
    return i;
}