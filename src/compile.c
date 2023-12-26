/*
 * Hello world
 */

#include "includes.h"

void compile_line(char *line, int line_count, m_list aliases, turing_ribbon *output)
{
    char **tokens = tokenize_line(line);
    if (!tokens) return;

    switch (tokens[0][0]) {
        case '/':
            break;

        case 'r':
            inst_add_alias(line_count, tokens, aliases);
            break;

        case '1':
            inst_set_bit(line_count, tokens, aliases, output);
            break;

        case '0':
            inst_set_bit(line_count, tokens, aliases, output);
            break;

        default:
            my_printf("WARNING: L.%i;b:0123456789abcdef%: starts with char \"%c%\" (ascii %i%) which is not recognised !\n", line_count, line[0], line[0]);
            break;
    }
    free_tokens(tokens);
}