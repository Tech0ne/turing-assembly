/*
 * Hello world
 */

#include "includes.h"

int main(int argc, char** argv, char** envp)
{
    turing_ribbon *ribbon = create_ribbon();
    repr_ribbon(ribbon);
    ribbon->pos += 24;
    set_bit(ribbon);
    repr_ribbon(ribbon);
    delete_ribbon(ribbon);
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
