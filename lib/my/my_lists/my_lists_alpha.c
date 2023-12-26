/*
** EPITECH PROJECT, 2023
** lib - lists
** File description:
** Alpha file - lists
*/

#include "../includes.h"

m_list              m_list_create(void *data)
{
    m_list current = malloc(sizeof(_m_list));
    current->prev = NULL;
    current->data = data;
    current->next = NULL;

    return current;
}

m_list              m_list_append(m_list ref, m_list obj)
{
    if (!ref)
        return obj;
    m_list c = ref;
    for (; c->next; c = c->next);
    c->next = obj;
    if (obj)
        obj->prev = c;

    return c->next;
}

m_list              m_list_prepend(m_list ref, m_list obj)
{
    if (!ref)
        return obj;
    m_list c = ref;
    for (; c->prev; c = c->prev);
    c->prev = obj;
    if (obj)
        obj->next = c;
    return c->prev;
}

m_list              m_list_set_before(m_list ref, m_list obj)
{
    if (!ref)
        return obj;
    if (obj) {
        obj->prev = ref->prev;
        obj->next = ref;
    }
    if (ref->prev)
        ref->prev->next = obj;
    ref->prev = obj;

    return obj;
}

m_list              m_list_set_after(m_list ref, m_list obj)
{
    if (!ref)
        return obj;
    if (obj) {
        obj->next = ref->next;
        obj->prev = ref;
    }
    if (ref->next)
        ref->next->prev = obj;
    ref->next = obj;

    return obj;
}
