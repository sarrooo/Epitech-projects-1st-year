##
## EPITECH PROJECT, 2020
## my_printf
## File description:
## Makefile
##

SRC		=		my_printf.c \
				my_putstr.c \
				my_putstr_octale.c \
				my_strdup.c \
				my_put_nbr.c \
				my_put_unsigned_nbr.c \
				my_strcpy.c \
				my_compute_power_rec.c\
				my_get_base.c \
				my_putchar.c \
				my_revstr.c \
				my_strlen.c \
				scan_flags.c \
				my_getnbr.c \
				display_space.c \
				my_putchar_flags.c \
				my_intlen.c \
				my_show_word_array.c \

OBJ		=		$(SRC:.c=.o)

CFLAGS	=	-I./ -g -g3

NAME	=		libmy.a

all:	$(NAME) clean

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf *.o

fclean:	clean
	rm $(NAME)

re:	clean all
