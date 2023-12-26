/*
** EPITECH PROJECT, 2023
** lib - list
** File description:
** Bravo file - lists
*/

#include "../includes.h"

void                m_list_remove(m_list obj, bool was_malloced)
{
    if (!obj)
        return;
    if (obj->prev)
        obj->prev->next = obj->next;
    if (obj->next)
        obj->next->prev = obj->prev;
    if (was_malloced)
        free(obj->data);
    free(obj);
}

void                m_list_destroy(m_list obj, bool was_malloced)
{
    if (!obj)
        return;
    m_list c = obj;
    for (; c->prev; c = c->prev);
    for (; c->next; c = c->next) {
        if (!c->prev)
            continue;
        m_list_remove(c->prev, was_malloced);
    }
    m_list_remove(c->prev, was_malloced);
    m_list_remove(c, was_malloced);
}
