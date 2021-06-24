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
		cp antman/compress ./
		make -C giantman/
		cp giantman/uncompress ./

clean:
	make clean -C antman/
	make clean -C giantman/

fclean:
	make fclean -C antman/
	rm compress
	make fclean -C giantman/
	rm uncompress

re:	fclean all
