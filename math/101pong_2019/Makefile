##
## EPITECH PROJECT, 2019
## 101pong
## File description:
## Makefile
##

MAIN	=	main.c\

SRC	=	pong.c\

NAME	=	101pong

TESTS	=	tests/tests_pong.c\
		tests/tests_pong2.c\
		tests/tests_pong3.c

OBJ	=	$(SRC:.c=.o)

FLAGS	=	-l m

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(MAIN) $(SRC) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o unit_tests $(SRC) $(TESTS) --coverage -l criterion -l m
	./unit_tests
