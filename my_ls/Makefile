##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for eval_expr
##

SRC     =	my_ls.c		\
		detect.c	\
		detect_2.c	\
		option.c	\
		print.c		\
		sort.c		\
		sort_2.c	\
		sort_h.c	\
		int_to_str.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

LIB	=	-L lib/ -lmy

CFLAGS	=	-I./ -g -g3

all:	lib1 $(NAME) clean

lib1:
	make -C lib/
	make clean -C lib/

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
