##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=		src/main.c					\
				src/init.c					\
				src/tools.c					\
				src/tools_bis.c				\
				src/tools_ter.c				\
				src/path.c					\
				src/shell.c					\
				src/exec_cmd.c				\
				src/return_value.c			\
				src/redirect.c				\
				src/get_data.c				\
				src/errors.c				\
				src/process.c				\
				src/builtins/env.c			\
				src/builtins/setenv.c		\
				src/builtins/unsetenv.c		\
				src/builtins/exit.c			\
				src/builtins/cd.c			\
				src/tokens/semicolons.c	 	\
				src/tokens/pipes.c			\
				src/tokens/right_redir.c 	\
				src/tokens/left_redir.c 	\

OBJ		=		$(SRC:.c=.o)

CFLAGS	=		-L lib/my -lmy -I include/ -Wextra -Wall

DFLAGS	=		-L lib/my -lmy -I include/ -g

NAME	=		mysh

all:		$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm	-f 	$(OBJ)
	make clean -C lib/my

fclean: clean
	rm 	-f 	$(NAME)
	make fclean -C lib/my

re:	fclean	all

valgrind: re
		valgrind --leak-check=full --track-origins=yes ./$(NAME)