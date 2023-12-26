##
## EPITECH PROJECT, 2023
## libmy
## File description:
## Makefile
##

SRC			=	$(wildcard *.c) \
				$(wildcard my_debug/*.c) \
				$(wildcard my_lists/*.c) \
				$(wildcard my_printf/*.c)

HEADERS		=	includes.h				\
				h_headers.h				\
				h_lib.h					\
				h_lists.h				\
				h_macros.h				\
				h_types.h				\
				h_debug.h				\
				h_printf.h

OBJ			=	$(SRC:.c=.o)

NAME		=	libmy.a

DEBUG_FLAGS	=	-Wall -Wextra -g3

$(NAME):	all

all:		compile

%.o: %.c
	gcc $(CPPFLAGS) -c $(CFLAGS) $< -o $@

compile:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(HEADERS) ../../includes/lib/
	cp $(NAME) ../

debug:
	gcc -c $(SRC) $(DEBUG_FLAGS)
	ar rc $(NAME) $(OBJ)
	cp $(HEADERS) ../../includes/lib/
	cp $(NAME) ../

clean:
	rm -rf *~
	rm -rf \#*\#
	rm -rf $(OBJ)

fclean:		clean
	rm -rf ../../includes/lib/*
	rm -rf ../$(NAME)
	rm -rf $(NAME)

re:			fclean	compile

re-debug:	fclean debug
