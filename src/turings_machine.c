/*
 * Hello world
*/

#include "includes.h"

bool get_bit(turing_ribbon *ribbon) {
    while (ribbon->pos >= (int)(ribbon->size * 8) || ribbon->pos < 0) m_realloc(ribbon);
    return (ribbon->ribbon[ribbon->pos / 8] & (1 << (ribbon->pos % 8))) != 0;
}

void set_bit(turing_ribbon *ribbon)
{
    while (ribbon->pos >= (int)(ribbon->size * 8) || ribbon->pos < 0) m_realloc(ribbon);
    ribbon->ribbon[ribbon->pos / 8] |= (1 << (ribbon->pos % 8));
}

void clear_bit(turing_ribbon *ribbon)
{
    while (ribbon->pos >= (int)(ribbon->size * 8) || ribbon->pos < 0) m_realloc(ribbon);
    ribbon->ribbon[ribbon->pos / 8] &= ~(1 << (ribbon->pos % 8));
}

void repr_ribbon(turing_ribbon *ribbon)
{
    printf("== Repr ribbon ==\n");
    printf("- Pos : %i\n- Size : %i\n", ribbon->pos, ribbon->size);
    int initial_pos = ribbon->pos;
    ribbon->pos = 0;
    if (!initial_pos)
        printf("{%i}", get_bit(ribbon));
    else
        printf("%i", get_bit(ribbon));
    for (int i = 1; i < (int)(ribbon->size * 8); i++) {
        ribbon->pos += 1;
        if (i == initial_pos)
            printf(" {%i}", get_bit(ribbon));
        else
            printf(" %i", get_bit(ribbon));
    }
    printf("\n");
    ribbon->pos = initial_pos;
}

int get_ribbon(char *token, m_list aliases)
{
    if (token[0] == 'r') return my_getnbr_base(&token[1], "0123456789abcdef");
    if (!aliases) return -1;
    int i = 0;
    m_list currrent = aliases;
    for (; currrent; currrent = currrent->next) {
        if (!my_strcmp(token, (char*)currrent->data)) return i;
        i++;
    }
    return -1;
}

void copy_bits(turing_ribbon *dst, turing_ribbon *src, int amount)
{
    for (int i = 0; i < amount; i++) {
        if (get_bit(src)) set_bit(dst);
        else clear_bit(dst);
        dst->pos += 1;
        src->pos += 1;
    }
}

void add_bits(turing_ribbon *ribbon, char *bitarray, short offset, int amount)
{
    turing_ribbon *tmp = create_ribbon();
    free(tmp->ribbon);
    tmp->ribbon = bitarray;
    tmp->pos = offset;
    copy_bits(ribbon, tmp, amount);
    free(tmp);
}

void add_inst(turing_ribbon *ribbon, instruction_id instruction)
{
    for (int i = 0; i < 4; i++) {
        if ((instruction & (1 << i)) != 0) set_bit(ribbon);
        else clear_bit(ribbon);
        ribbon->pos += 1;
    }
}

void add_int(turing_ribbon *ribbon, int value)
{
    for (int i = 0; i < (int)(8 * sizeof(int)); i++) {
        if ((value & (1 << i)) != 0) set_bit(ribbon);
        else clear_bit(ribbon);
        ribbon->pos += 1;
    }
}

void add_char(turing_ribbon *ribbon, char value)
{
    for (int i = 0; i < 8; i++) {
        if ((value & (1 << i)) != 0) set_bit(ribbon);
        else clear_bit(ribbon);
        ribbon->pos += 1;
    }
}

turing_ribbon *create_ribbon(void)
{
    turing_ribbon *new_obj = (turing_ribbon*)malloc(sizeof(turing_ribbon));
    new_obj->ribbon = (char*)malloc(2);
    new_obj->pos = 0;
    new_obj->size = 2;
    return new_obj;
}

void delete_ribbon(turing_ribbon *ribbon)
{
    free(ribbon->ribbon);
    free(ribbon);
}
