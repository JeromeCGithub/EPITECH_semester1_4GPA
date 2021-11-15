##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make a file
##

SRC	=	src/main.c\
		display_list.c\
		src/init_list.c\
		src/action.c\
		src/update_screen.c\
		src/radix.c\
		src/push.c\
		lib/my_getnbr.c\
		lib/my_putnbr.c\
		lib/my_putchar.c\
		lib/my_strlen.c\

SRCT	=	src/init_list.c\
		src/action.c\
		src/radix.c\
		src/push.c\
		lib/my_getnbr.c\
		lib/my_putchar.c\
		lib/my_putnbr.c\
		lib/my_strlen.c\

TESTS	=	tests/test_pushswap.c\
		tests/tests_lib.c

OBJ	=	$(SRC:.c=.o)

FLAGS   =       -l csfml-window -l csfml-system -l csfml-audio -lcsfml-graphics -lm

NAME	=	push_swap

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -I./include -g $(FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o unit_tests $(SRCT) $(TESTS) -I./include --coverage -lcriterion
	./unit_tests

cleangc:
	rm *.gcno
	rm *.gcda
