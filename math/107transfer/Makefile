##
## EPITECH PROJECT, 2019
## 107transfer
## File description:
## Makefile
##

MAIN	=	src/main.c

SRC	=	src/help.c\
		src/my_engine.c\

TESTS	=

NAME	=	107transfer

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(MAIN) $(SRC) -I./include -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o unit_tests $(SRC) $(TESTS) -I./include --coverage -lcriterion
	./unit_tests

cleangc:
	rm *.gcno
	rm *.gcda
