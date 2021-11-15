##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make a file
##

SRC	=	src/bsq.c\
		src/input_tabint.c\
		src/find_best_square.c\
		src/change_tab.c\
		lib/my_getnbr.c\
		lib/my_putstr.c\
		lib/my_strlen.c\
		lib/my_putchar.c\
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

TESTFILE	=	tests/tests_lib.c\
			tests/tests_bsq.c\
			tests/tests_bsq2.c

SRCTEST	=	src/input_tabint.c\
		src/bsq.c\
		src/find_best_square.c\
		src/change_tab.c\
		lib/my_getnbr.c\
		lib/my_putstr.c\
		lib/my_strlen.c\
		lib/my_putchar.c

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

tests_run:	$(OBJ)
	gcc -o unit_tests $(SRCTEST) $(TESTFILE) --coverage -lcriterion
	./unit_tests

cleangc:
	rm *.gcno
	rm *.gcda
