##
## EPITECH PROJECT, 2020
## 105torus
## File description:
## Makefile
##

MAIN	=	main.c

SRC	=	src/help.c\
		src/secante.c\
		src/newton.c\
		src/bisection.c\
		src/error_handling.c\
		src/derive.c\
		src/calc_result.c\

LIB	=	lib/my_strcmp.c\

OBJ	=	$(SRC:.c=.o) $(MAIN:.c=.o) $(LIB:.c=.o)

TEST	=	tests/test_help.c\

NAME	=	105torus

CFLAGS	=	-I./include

CPPFLAGS	=	-lm

CRIT	=	-l criterion --coverage

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o unit_tests $(TEST) $(SRC) $(LIB) $(CFLAGS) $(CRIT)
	./unit_tests
