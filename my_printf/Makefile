##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for bootstrap
##

SRC     =	lib/my/my_strlen.c	\
		lib/my/my_putchar.c	\
		lib/my/my_putstr.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_revstr.c	\
		lib/my/my_strcat.c	\
		lib/my/my_strcmp.c	\
		lib/my/my_strncat.c	\
		lib/my/my_strncmp.c	\
		lib/my/my_put_uns.c	\
		my_printf.c	\
		my_printf1.c	\
		detect_index.c	\
		print_index.c	\
		print_width.c	\
		print_prec.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./ -g -g3

NAME	=	libmy.a

BIN	=	a.out

PRT	=	-L libmy.a

all:	libbsprintf.a

libbsprintf.a:	$(OBJ)
	ar rc $(NAME) $(OBJ)

compil : $(OBJ)
	gcc -o $(BIN) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
