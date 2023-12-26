/*
 * Hello world
 */

#include "includes.h"

char *remove_ignors(const char *line, const char *ignores)
{
    int final_size = my_strlen(line);
    for (int i = 0; ignores[i]; i++)
        final_size -= my_str_count(line, ignores[i]);
    if (!final_size) return NULL;
    char *final_string = malloc(final_size + 1);
    int pos = 0;
    for (int i = 0; line[i]; i++)
        if (my_str_get_index(ignores, line[i]) == -1)
            final_string[pos++] = line[i];
    final_string[final_size] = 0;
    return final_string;
}

char **tokenize_line(const char *line)
{
    char ignore_chars[] = " \t\n";
    char *new_line = remove_ignors(line, ignore_chars);
    if (!new_line) return NULL;

    int split_count = my_str_count(new_line, SPLIT_CHAR);
    char **splits = malloc(sizeof(char*) * (split_count + 2));
    int pos = 0, size = 0;

    for (int i = 0; i < split_count; i++) {
        size = my_str_get_index(&new_line[pos], SPLIT_CHAR);
        splits[i] = my_strndup(&new_line[pos], size);
        pos += size + 1;
    }
    splits[split_count] = my_strdup(&new_line[pos]);
    splits[split_count + 1] = NULL;

    free(new_line);

    return splits;
}

void free_tokens(char **tokens)
{
    for (int i = 0; tokens[i]; i++) {
        printf("Freeing token %i : %s\n", i, tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
}