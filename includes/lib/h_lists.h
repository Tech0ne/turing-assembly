/*
** EPITECH PROJECT, 2023
** lib - lists
** File description:
** Lists headers (linked lists)
*/

#ifndef INCLUDED_LIB_LISTS_H
    #define INCLUDED_LIB_LISTS_H

    #include "includes.h"

    #define m_list _m_list *

typedef struct _m_list {
    struct _m_list *prev;
    void *data;
    struct _m_list *next;
} _m_list;

m_list              m_list_create(void *data);
m_list              m_list_append(m_list ref, m_list obj);
m_list              m_list_prepend(m_list ref, m_list obj);
m_list              m_list_set_before(m_list ref, m_list obj);
m_list              m_list_set_after(m_list ref, m_list obj);

void                m_list_remove(m_list obj, bool was_malloced);
void                m_list_destroy(m_list obj, bool was_malloced);

#endif
