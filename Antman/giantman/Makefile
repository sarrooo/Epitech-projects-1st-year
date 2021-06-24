##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 
##

SRC     =	giantman.c		\
			files.c			\
			array_code.c	\
			code.c			\

OBJ	=	$(SRC:.c=.o)

LIB	=	-L ../lib/ -lmy

CFLAGS	=	-I./ -g -g3

NAME	=	uncompress

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
