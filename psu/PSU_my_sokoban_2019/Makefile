##
## EPITECH PROJECT, 2019
## 101pong
## File description:
## Makefile
##

SRC	=	src/moove.c\
		src/check_moove.c\
		src/print_h.c\
		src/manage_size.c\
		src/win.c\
		src/sokoban.c\
		src/store_map.c\
		src/free_all.c\
		src/error_handling.c\
		lib/my_putstr.c\
		lib/read_it.c\
		lib/my_strlen.c\
		lib/display_map.c\
		lib/find_coll.c

SRCT	=	src/moove.c\
		src/check_moove.c\
		src/win.c\
		src/free_all.c\
		src/store_map.c\
		src/error_handling.c\
		lib/read_it.c\
		lib/my_strlen.c\
		lib/find_coll.c

NAME	=	my_sokoban

OBJ	=	$(SRC:.c=.o)

FLAGS	=	-l ncurses

TESTS	=	tests/test_sokoban1.c\
		tests/test_sokoban2.c\
		tests/test_sokoban3.c\
		tests/test_sokoban4.c\
		tests/test_sokoban5.c\

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -g -o $(NAME) src/main.c $(SRC) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o unit_tests $(SRCT) $(TESTS) $(FLAGS) --coverage -lcriterion -lm
	./unit_tests

cleangc:
	rm *.gcno
	rm *.gcda
