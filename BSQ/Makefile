##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 
##

SRC     =	algorithms.c	\
		algrorithms1.c	\
		mem_alloc.c	\
		read_arrays.c	\
		read_arr1.c	\
		read_files.c	\
		read_files1.c	\
		my_putchar.c	\
		my_getnbr.c	\
		my_strlen.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_show_word_array.c	\
		bsq.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./ -g -g3

NAME	=	bsq

all:	bsq clean

bsq:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
