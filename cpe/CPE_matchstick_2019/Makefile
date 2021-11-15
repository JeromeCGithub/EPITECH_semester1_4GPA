##
## EPITECH PROJECT, 2019
## 101pong
## File description:
## Makefile
##

SRC	=	src/main.c\
		src/game.c\
		src/player.c\
		src/ia.c\
		src/ia_lib.c\
		src/ia_lib2.c\
		src/is_win.c\
		src/error_handling.c\
		lib/my_atoi.c\
		lib/get_next_line.c\
		lib/my_put_nbr.c\
		lib/my_putchar.c\


SRCTEST	=	src/game.c\
		src/player.c\
		src/ia.c\
		src/ia_lib.c\
		src/ia_lib2.c\
		src/is_win.c\
		src/error_handling.c\
		lib/my_atoi.c\
		lib/get_next_line.c\
		lib/my_put_nbr.c\
		lib/my_putchar.c\

TESTFILE	=	tests/test_matchstick.c\
			tests/test_matchstick2.c\
			tests/test_gnl.c\

NAME	=	matchstick

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):
	gcc -g -o $(NAME) $(SRC) -I./include

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o unit_tests $(SRCTEST) $(TESTFILE) --coverage -lcriterion -I./include
	./unit_tests

cleangc:
	rm *.gcno
	rm *.gcda
