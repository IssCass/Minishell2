##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=		my_putchar.c                    	\
				my_put_nbr.c                    	\
				my_putstr.c                     	\
				my_strlen.c                     	\
				my_getnbr.c                     	\
				my_printf.c 						\
				functions_printf.c 					\
				functions_printf_2.c 				\
				functions_printf_3.c 				\
				my_put_unsigned.c 					\
				my_array_to_int.c 					\
				my_revstr.c 						\
				my_strcat.c 						\
				my_strcmp.c 						\
				my_strcpy.c 						\
				my_strlenalphab.c 					\
				my_strncat.c 						\
				my_strncmp.c 						\
				my_strtol.c 						\
				swap_elem.c							\
				my_str_to_word_array.c				\
				get_next_line.c						\
				tools_tab.c						    \
				my_strdup.c

NAME	=	libmy.a

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I ../../include/

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
	rm 	-f 	$(NAME)

re:	fclean	all