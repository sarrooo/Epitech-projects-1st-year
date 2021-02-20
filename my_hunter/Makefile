##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for eval_expr
##

SRC     =	my_hunter.c	\
		event.c		\
		buffer.c	\
		window.c	\
		description.c	\
		sprite.c	\
		sprite2.c	\
		score.c		\
		text.c		\
		level.c		\
		end.c		\
		start.c		\
		music.c		\
		end_2.c		\
		text_2.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

LIB	=	-L lib/ -lmy

CSFML	=	-l csfml-graphics -lcsfml-audio -lcsfml-graphics

CSFML1	=	-lcsfml-system -lcsfml-network -lcsfml-window

CFLAGS	=	-I./ -g -g3

all:	lib1 $(NAME) clean

lib1:
	make -C lib/
	make clean -C lib/

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB) $(CSFML) $(CSFML1)
	touch hight_score.txt
	chmod 777 hight_score.txt

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
