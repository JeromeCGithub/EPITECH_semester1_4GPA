##
## EPITECH PROJECT, 2019
## 107transfer
## File description:
## Makefile
##

MAIN	=	src/main.c

SRC	=	src/help.c\
		src/my_engine.c\
		src/error_handling.c\
		src/parser.c\

TESTS	=	tests/test_error_handling.c\
		tests/test_help.c\
		tests/test_engine.c\

NAME	=	107transfer

OBJ	=	$(SRC:.c=.o) $(MAIN:.c=.o)

CPPFLAGS	=	-I./include

CC	=	gcc -o $(NAME)

LDFLAGS	=	-lm

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(LDFLAGS)

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
