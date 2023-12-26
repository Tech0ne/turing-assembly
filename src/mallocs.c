/*
 * Hello world
 */

#include "includes.h"

void m_realloc(turing_ribbon *ribbon)
{
    if (ribbon->size >= CHUNK_SIZE) {
        while (ribbon->pos < 0) {
            printf("Negativ value retrived\n");
            ribbon->pos += ribbon->size;
        }
        ribbon->pos %= ribbon->size;
    }
    unsigned long new_size = ribbon->size + CHUNK_SIZE;
    if (new_size >= CHUNK_SIZE) new_size = CHUNK_SIZE;
    
    char *new_ribbon = (char*)malloc(new_size);
    bool add_forward = (ribbon->pos >= 0);
    if (add_forward) {
        my_memset(&new_ribbon[ribbon->size], 0, CHUNK_SIZE);
        my_strncpy(new_ribbon, ribbon->ribbon, ribbon->size);
    } else {
        my_memset(new_ribbon, 0, CHUNK_SIZE);
        my_strncpy(&new_ribbon[CHUNK_SIZE], ribbon->ribbon, ribbon->size);
    }
    free(ribbon->ribbon);
    ribbon->ribbon = new_ribbon;
    if (!add_forward) ribbon->pos += CHUNK_SIZE * 8;
    ribbon->size = new_size;
    while (ribbon->pos < 0) {
        printf("Negativ value retrived\n");
        ribbon->pos += ribbon->size;
    }
    ribbon->pos %= ribbon->size;
}