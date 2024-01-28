/*
 * Hello world
 */

#ifndef INCLUDED_PROJECT_H
#define INCLUDED_PROJECT_H

#include "includes.h"

typedef struct turing_ribbon {
    char *ribbon;
    int pos;
    size_t size;
} turing_ribbon;

typedef struct alias {
    char *alpha;
    char *bravo;
} alias;

typedef enum instruction_id {
    END_PROGRAM,
    CLEAR_BIT,
    SET_BIT,
    INVERT_BIT,
    MOVE_LEFT,
    MOVE_RIGHT,
    RUN_IF,
    RUN_ELSE,
    RUN_ENDIF,
    COPY_BITS,
    BOOL_AND,
    BOOL_OR,
    CALL_FUNCTION,
    CALL_RIBBON,
} instruction_id;

//========================= compile.c =========================

/// @brief "Compile" a line into bits (represented as a char array)
/// @param line The line as turring code
/// @param line_count The line nb, used when warning
/// @param aliases A list of aliases, representing ribbons
/// @param output The output ribbon, containing the actual run code
void compile_line(char *line, int line_count, m_list aliases, turing_ribbon *output);

//========================= instructions.c =========================

/// @brief Run the special {register}, {name} instruction (setting an alias)
/// @param line_count The current line number (used in case of a warning)
/// @param tokens The tokenized line
/// @param aliases The list of alias, where we will add our registery name
void inst_add_alias(int line_count, char **tokens, m_list aliases);

/// @brief Used with the 0 and 1 operations
/// @param line_count The current line nb
/// @param tokens Tokenized version of the current line
/// @param aliases list of aliases
/// @param ribbon Output ribbon
void inst_set_bit(int line_count, char **tokens, m_list aliases, turing_ribbon *ribbon);

//========================= mallocs.c =========================

/// @brief Realloc the ribbon itself in the structure to the new size, by adding chars where needed
/// @param ribbon The ribbon to change size
void m_realloc(turing_ribbon *ribbon);


//========================= my_getnbr_base.c =========================

/// @brief Return an int from any base
/// @param str The actual number in the base provided
/// @param base The actual base, as a char array
/// @return The "decoded" int
int my_getnbr_base(const char *str, const char *base);

//========================= my_lists.c =========================

/// @brief Get the length of a list (from the given point)
/// @param liste The list to check
/// @return The length of the list (from the given point)
int my_list_length(m_list liste);

//========================= tokenize.c =========================

/// @brief Split the line into tokens, ignoring special chars (' ', '\t' and '\n')
/// @param line The line to tokenize
/// @return A string array, containing each token, ending with a NULL pointer
char **tokenize_line(const char *line);

/// @brief Free a char ** map
/// @param tokens Char map to be freed
void free_tokens(char **tokens);

//========================= turings_machine.c =========================

/// @brief Get bit at address pointed by the ribbon structure
/// @param ribbon The ribbon structure to check
/// @return 1 or 0, depending of the bit
bool get_bit(turing_ribbon *ribbon);

/// @brief Set the bit at address pointed by the ribbon structure to 1
/// @param ribbon The ribbon structure to change
void set_bit(turing_ribbon *ribbon);

/// @brief Set the bit at address pointed by the ribbon structure to 0
/// @param ribbon The ribbon structure to change
void clear_bit(turing_ribbon *ribbon);

void repr_ribbon(turing_ribbon *ribbon);

/// @brief Get the values of a ribbon/register, either as a literal r-value, or as an alias
/// @param token The token that should contain the register nb
/// @param aliases Alias list, containing all aliases
/// @return The register nb, or -1
int get_ribbon(char *token, m_list aliases);


/// @brief Add a given amount of bits from the bytearray (using the offset)
/// @param ribbon The target ribbon (this action WILL update the position)
/// @param bitarray The char map to extract bits from
/// @param offset The offset to use on the char map (0 to start from the begining)
/// @param amount The amount of bits to copy
void add_bits(turing_ribbon *ribbon, char *bitarray, short offset, int amount);

void add_inst(turing_ribbon *ribbon, instruction_id instruction);

void add_int(turing_ribbon *ribbon, int value);

/// @brief Add a char (8 bits) to a ribbon
/// @param ribbon The targetted ribbon
/// @param value The char (byte) to add
void add_char(turing_ribbon *ribbon, char value);

/// @brief Create a new "empty" ribbon (with 8 bits, by default)
/// @return A new, ready to use, turing ribbon
turing_ribbon *create_ribbon(void);

/// @brief Delete a ribbon, by freeing it's char map and itself
/// @param ribbon The ribbon to destroy
void delete_ribbon(turing_ribbon *ribbon);

#endif
