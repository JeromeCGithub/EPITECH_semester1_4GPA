##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make a file
##

SRC	=	get_next_line.c

TESTS	=	tests/test_gnl.c

OBJ	=	$(SRC:.c=.o)

NAME	=	gnl

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -I./include

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
