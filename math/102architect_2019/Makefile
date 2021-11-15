##
## EPITECH PROJECT, 2019
## 102architect
## File description:
## Makefile
##

MAIN	=	src/main.c\

SRC	=	src/print_h.c\
		src/parser.c\
		src/multiply_matrice.c\
		src/display_matrice.c\
		src/init.c\
		src/modify_matrice.c\
		src/error_handling.c

TEST	=	tests/test_display_matrice.c\
		tests/test_print_h.c\
		tests/test_init.c\
		tests/test_multiplicate.c\
		tests/test_modify_matrice.c\
		tests/test_parser.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	102architect

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(MAIN) $(SRC) -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o unit_tests $(SRC) $(TEST) -l m -l criterion --coverage
	./unit_tests
