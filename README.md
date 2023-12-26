# Turing's Assembly

---

Hello world !

Today, I present you Turing's Assembly !

This is a project based on the famous [Turing machine](https://en.wikipedia.org/wiki/Turing_machine).

The goal of this project is to extend the concept into something more than a theorical concept.

So, I made an assembly-like programing language, with a C-based pseudo-compiler, and a runner (don't worry, it's same binary).

The goal is to open the Turing concept to non-programers that just want to experiment and play.

## Requirements

The only real requirement is a C compiler (I advise GCC).

You _might_ want to use `make` to compile (as doing all the commands by hand is quite anoying), but it's up to you.

_Please note that I wont provide documentation about how to compile without using `make`_

## How to use

To use this, follow these steps :

- Compile the code (use the `make` command to make is easy)
  - Please note : If you are running on Windows, please follow the instructions on [this]() wiki page for compilation.
- Run the binary with the `-h` or `--help` flag to display in terminal help
- If you want to compile a Turing Assembly file, run `./turing_assembly compile {your_ta_file}`. This will generate you a .co object, which is a binary representation of your program (use tools like hexyl or hexdump to display). Use `./turing_assembly help compile` to see more infos
- To run a .co object, use `./turing_assembly run {your_co_file}`. This will read your co file and execute it. Use `./turing_assembly help run` to see more infos

To create your own Turing Assembly program, please visit [this]() page, to have a list of all the instructions (Remember, this is a esolang ;), don't wait a high level syntaxe...)

Feel free to change the [configs.h]() file to change ribbons size, max ribbons...