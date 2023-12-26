/*
 * Hello world
 */

#include "includes.h"

int main(int argc, char** argv, char** envp)
{
    char *str = malloc(5);
    my_strcpy(str, "abcde");
    convert_to_big_endian(str, 5);
    printf("%s\n", str);
    // turing_ribbon *ribbon = create_ribbon();
    // char *tokens[] = {
    //     "1",
    //     "r123",
    //     "f",
    //     NULL,
    // };
    // inst_set_bit(2, tokens, NULL, ribbon);
    // repr_ribbon(ribbon);
    // delete_ribbon(ribbon);
}