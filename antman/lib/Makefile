##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for bootstrap
##

SRC     =	my_strlen.c		\
		my_revstr.c		\
		my_putchar.c		\
		my_putstr.c		\
		my_put_nbr.c		\
		my_getnbr.c		\
		my_strcmp.c		\
		my_strncpy.c		\
		my_show_word_array.c	\
		my_printf/my_put_uns.c	\
		my_printf/my_printf.c	\
		my_printf/my_printf1.c	\
		my_printf/detect_index.c\
		my_printf/print_index.c	\
		my_printf/print_width.c	\
		my_printf/print_prec.c	\
		int_to_str.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./ -g -g3

NAME	=	libmy.a

all:	libbsprintf.a clean

libbsprintf.a:	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
