##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

# Defining some important variables

SRC					= $(wildcard src/*.c)	\
					  $(wildcard libs/*.c)

NAME				= turing_assembly
DEBUG_NAME			= $(NAME)-debug
LIB					= ./lib/my/
LIBNAME				= libmy.a
HEADERS				= ./includes/
FLAGS				= -L$(LIB) -lmy -I$(HEADERS)
DEBUG_FLAGS			= -Wall -Wextra -g3
OBJ					= $(SRC:.c=.o)

CC					= gcc
CFLAGS		   	   ?= $(FLAGS)

# Defining $(ECHO), a custom echoing function that display a percentage

ifndef ECHO
    HIT_TOTAL != ${MAKE} ${MAKECMDGOALS} --dry-run ECHO="HIT_MARK" | grep -c "HIT_MARK"
    HIT_COUNT = $(eval HIT_N != expr ${HIT_N} + 1)${HIT_N}
    ECHO = echo "[\033[90m`expr ${HIT_COUNT} '*' 100 / ${HIT_TOTAL}`%\033[0m]"
endif

all:
	@$(ECHO) Starting compilation !
	@make compile --no-print-directory
	@$(ECHO) Compilation successfull !

$(NAME):			all

compile:			$(LIBNAME)	$(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

debug:
	@$(ECHO) Starting debug compilation !
	@make compile --no-print-directory CFLAGS="$(FLAGS) $(DEBUG_FLAGS)"
	@$(ECHO) Debug compilation success !

$(LIBNAME):
	@$(ECHO) Starting lib compilation !
	@make -C $(LIB) --no-print-directory
	@$(ECHO) Lib compiled Successfully

%.o:				%.c
	@$(ECHO) Compiling $< to $@
	@$(CC) $(CPPFLAGS) -c $(CFLAGS) $< -o $@

clean:
	@$(ECHO) Starting project cleaning !
	@make -C $(LIB) clean --no-print-directory
	@find . -name *~ -delete
	@find . -name *.swp -delete
	@rm -f $(OBJ)
	@find . -name vgcore* -delete
	@$(ECHO) Project cleaning successfull !

fclean:				clean
	@$(ECHO) Starting project purge !
	@make -C $(LIB) fclean --no-print-directory
	@rm -rf $(NAME)
	@rm -rf $(DEBUG_NAME)
	@$(ECHO) Successfully purged the project !


check_functions: 	$(LIBNAME) compile
	@epitech_function_checker $(NAME)

cs:					check_functions debug fclean
	@abricot .
	@$(ECHO) --- report made ---

re:
	@make fclean --no-print-directory
	@echo
	@make compile --no-print-directory

re-debug:
	@make fclean --no-print-directory
	@echo
	@make debug --no-print-directory

push: 				cs
	@echo
	@git pull
	@git add .
	@$(ECHO) -n "Commit message > "
	@read message; git commit -m "$$message"
	@git push

flow:
	cflow --tree --number $(SRC)
