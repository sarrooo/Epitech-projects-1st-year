##
## EPITECH PROJECT, 2020
## Navy
## File description:
## Makefile
##

SRC		=		navy.c \
				navy_h.c \
				navy_strcmp.c \
				connection.c \
				load_map.c \
				set_map.c \
				print_map.c \
				navy_signal.c \
				navy_pid.c \
				turnplayer1.c \
				send_pos.c \
				receive_pos.c \
				error_handling_map.c \
				update_map.c \

OBJ		=		$(SRC:.c=.o)

CFLAGS	=	-I./ -g -g3

NAME	=		navy

all:	$(NAME) clean

$(NAME):	$(OBJ)
	make -C printf/
	gcc -o $(NAME) $(OBJ) -L printf/ -lmy

clean:
	rm -rf *.o
	rm -rf *~

fclean: clean
	make fclean -C printf/
	rm -f $(NAME)

re:	fclean all
