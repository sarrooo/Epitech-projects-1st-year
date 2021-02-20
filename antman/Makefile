##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 
##

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./ -g -g3

all:	ant_giant

ant_giant:
		make -C antman/
		make -C giantman/

clean:
	make clean -C antman/
	make clean -C giantman/

fclean:
	make fclean -C antman/
	make fclean -C giantman/

re:	fclean all
