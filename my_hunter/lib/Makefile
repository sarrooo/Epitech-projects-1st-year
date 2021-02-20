##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for bootstrap
##

SRC     =	my_strlen.c	\
		my_revstr.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_put_nbr.c	\
		my_getnbr.c	\
		my_strcmp.c	\
		my_put_uns.c	\
		my_printf.c	\
		my_printf1.c	\
		detect_index.c	\
		print_index.c	\
		print_width.c	\
		print_prec.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./ -g -g3

NAME	=	libmy.a

all:	libbsprintf.a

libbsprintf.a:	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
