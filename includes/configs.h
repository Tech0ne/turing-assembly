/*
 * Hello world
 */

#ifndef INCLUDED_CONFIGS_H
#define INCLUDED_CONFIGS_H

// PLEASE NOTE THAT IF YOU CHANGE SOME OF THESE LIMITS, YOU MIGHT HAVE TO CHANGE IN-CODE IMPLEMENTATIONS !!!

// Max bits per ribbon
#define MAX_RIBBON_SIZE 1024

// Max ribbons
#define MAX_RIBBONS 256 // This means the biggest ribbon will be rff (ribbon number 255)

// Define sizes of registers, as well as instructions
#define INST_SIZE 4     // each instruction will be 4 bits long
#define REG_SIZE 8      // each register nb will be 8 bits long
#define HEXA_SIZE 8     // each hexa values will be 8 bits long

// Define the number of memory chunk to add each time you make your ribbon bigger
// The bigger this number is, the less operations you will do, but you might end up with unused space (freed, of course, but still unused)
#define CHUNK_SIZE 2

// Authorised chars in ALIASES (using the "rX : Y" syntax)
// Do NOT change this config, as it might break the compilation and running
#define AUTHORISED_ALIAS_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ_"

// Max size for aliases
#define MAX_ALIAS_SIZE 8

// Char used to split args of an instruction (pay attention to what u use, as it might be used by something else)
// For example, you can use things like ',', '.', '$', '^', '='...
// Still, ',' is the most logical
#define SPLIT_CHAR ','

#endif
