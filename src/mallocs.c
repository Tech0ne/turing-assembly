/*
 * Hello world
 */

#include "includes.h"

void m_realloc(turing_ribbon *ribbon)
{
    size_t new_size;
    if (ribbon->pos > 0) {
        ribbon->pos %= (MAX_RIBBON_SIZE * 8);
        if (ribbon->pos < (ribbon->size * 8))
            return;
        new_size = ribbon->size;
        while (ribbon->pos > (new_size * 8))
            new_size += CHUNK_SIZE;
        realloc(ribbon->ribbon, new_size);
        ribbon->size = new_size;
    } else {
        ribbon->pos = -(-ribbon->pos % (MAX_RIBBON_SIZE * 8));
        if (ribbon->pos > -((MAX_RIBBON_SIZE / 2) * 8)) {
            ribbon->pos += MAX_RIBBON_SIZE;
            m_realloc(ribbon);
        } else {
            new_size = ribbon->size;
            new_size += (((-ribbon->pos) / 8) / 2) + 1;
            char* new_chuck = (char*)malloc(new_size);
            my_memset(new_chuck, 0, new_size);
        }
    }
    // if (ribbon->size >= MAX_RIBBON_SIZE) {
    //     while (ribbon->pos < 0) {
    //         printf("Negativ value retrived\n");
    //         ribbon->pos += ribbon->size * 8;
    //     }
    //     ribbon->pos %= ribbon->size;
    // }
    // unsigned long new_size = ribbon->size + CHUNK_SIZE;
    // if (new_size >= CHUNK_SIZE) new_size = CHUNK_SIZE;
    
    // char *new_ribbon = (char*)malloc(new_size);
    // bool add_forward = (ribbon->pos >= 0);
    // if (add_forward) {
    //     my_memset(&new_ribbon[ribbon->size], 0, CHUNK_SIZE);
    //     my_strncpy(new_ribbon, ribbon->ribbon, ribbon->size);
    // } else {
    //     my_memset(new_ribbon, 0, CHUNK_SIZE);
    //     my_strncpy(&new_ribbon[CHUNK_SIZE], ribbon->ribbon, ribbon->size);
    // }
    // free(ribbon->ribbon);
    // ribbon->ribbon = new_ribbon;
    // if (!add_forward) ribbon->pos += CHUNK_SIZE * 8;
    // ribbon->size = new_size;
    // while (ribbon->pos < 0) {
    //     printf("Negativ value retrived\n");
    //     ribbon->pos += ribbon->size;
    // }
    // ribbon->pos %= ribbon->size;
}
