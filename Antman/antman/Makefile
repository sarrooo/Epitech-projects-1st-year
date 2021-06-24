##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile for antan
##


SRC     =	antman.c			\
			files.c				\
			heap.c				\
			heap_2.c			\
			tree.c				\
			huff_compilation.c	\
			write_code.c		\

OBJ	=	$(SRC:.c=.o)

LIB	=	-L ../lib/ -lmy

CFLAGS	=	-I./ -g -g3

NAME	=	compress

all:	lib1 ant clean

ant:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB)

lib1:
	make -C ../lib/
	make clean -C ../lib/

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
