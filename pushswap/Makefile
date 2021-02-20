##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 
##

SRC     =	pushswap.c	\
			list.c		\
			list_2.c	\
			sort_list.c	\
			check_start.c	\
			operation_s.c	\
			operation_p.c	\
			operation_r.c	\
			operation_rr.c	\
			last.c		\
			sort_list_buff.c \

OBJ	=	$(SRC:.c=.o)

LIB	=	-L lib/ -lmy

CFLAGS	=	-I./ -g -g3

NAME	=	push_swap

all:	lib1 swap clean

swap:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB)

lib1:
	make -C lib/
	make clean -C lib/

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
