/*
 * Hello world
 */

#include "includes.h"

void inst_add_alias(int line_count, char **tokens, m_list aliases)
{
    if (!tokens[1]) {
        my_printf("WARNING: L.%i;b:0123456789abcdef%: Awaiting a second token. Only register name found.", line_count);
        return;
    }
    int nb = my_getnbr_base(&tokens[0][1], "0123456789abcdef");
    int list_length = my_list_length(aliases);
    if (nb != list_length) {
        my_printf("WARNING: L.%i;b:0123456789abcdef%: Register %i;b:0123456789abcdef% defined but awaiting defignition for register %i;b:0123456789abcdef%.\n", line_count, nb, list_length);
        return;
    }

    if (nb >= MAX_RIBBONS) {
        my_printf("WARNING: L.%i;b:0123456789abcdef%: Max amount of ribbons reached while trying to register a new ribbon with value %i;b:0123456789abcdef%\n", line_count, nb);
        return;
    }

    if (my_strlen(tokens[1]) > MAX_ALIAS_SIZE) {
        my_printf("WARNING: L.%i;b:0123456789abcdef%: Alias name too long (%i% chars instead of %i% maximum)", line_count, my_strlen(tokens[1]), MAX_ALIAS_SIZE);
    }

    for (int i = 0; tokens[1][i]; i++) {
        if (my_str_get_index(AUTHORISED_ALIAS_CHARS, tokens[1][i]) == -1) {
            my_printf("WARNING: L.%i;b:0123456789abcdef%: Unauthorised char in alias name : \"%c%\" (ascii %i%)", line_count, tokens[1][i], tokens[1][i]);
            return;
        }
    }

    m_list current = aliases;
    for (; current; current = current->next) {
        if (!my_strcmp(tokens[1], (char *)current->data)) {
            my_printf("WARNING: L.%i;b:0123456789abcdef%: Alias name already exists (%s%)", line_count, tokens[1]);
            return;
        }
    }

    m_list_append(aliases, m_list_create(my_strdup(tokens[1])));
}

void inst_set_bit(int line_count, char **tokens, m_list aliases, turing_ribbon *ribbon)
{
    if (my_strlen(tokens[0]) > 1) {
        my_printf("WARNING: L.%i;b:0123456789abcdef%: Instruction \"%s%\" is not recognised\n", line_count, tokens[0]);
        return;
    }

    int nb_tokens = 0;
    for (; tokens[nb_tokens]; nb_tokens++);
    if (nb_tokens < 2 || nb_tokens > 3) {
        my_printf("WARNING: L.%i;b:0123456789abcdef%: Instruction \"%s%\" require 1 or 2 argument(s), but %i% was given\n", line_count, tokens[0], nb_tokens - 1);
        return;
    }

    int reg = get_ribbon(tokens[1], aliases);
    int val = (nb_tokens == 2) ? 1 : my_getnbr_base(tokens[2], "0123456789abcdef");
    if (reg == -1 || val == -1) {
        my_printf("WARNING: L.%i;b:0123456789abcdef%: Could not read an argument\n", line_count);
        return;
    }
    add_inst(ribbon, (tokens[0][0] == '0') ? CLEAR_BIT : SET_BIT);
    add_int(ribbon, reg);
    add_int(ribbon, val);
}