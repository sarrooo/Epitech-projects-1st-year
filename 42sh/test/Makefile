##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make
##

.PHONY: fclean all

SRC 	=	$(wildcard ./*.c)

CFLAGS	=	-I./include -g3 -lcriterion --coverage

NAME	=	test

all: COMPIL

COMPIL:	$(SRC:.c=.o)
	@gcc -o $(NAME) $(SRC) $(CFLAGS)
	@echo "-> Done"

clean:
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	rm -f $(NAME)

re: fclean all