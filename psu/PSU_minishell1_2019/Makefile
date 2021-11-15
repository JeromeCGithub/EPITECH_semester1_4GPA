##
## EPITECH PROJECT, 2019
## minishell
## File description:
## Makefile
##

MAIN	=	src/main.c

SRC	=	src/get_next_line.c\
		src/unsetenv.c\
		src/manage_path.c\
		src/setenv.c\
		src/builtin.c\
		src/cd_builtin.c\
		src/my_str_to_word_array.c\

LIB	=	lib/my_strlen.c\
		lib/my_strcmp.c\
		lib/my_putchar.c\
		lib/my_putstr.c\
		lib/my_strcpy.c\
		lib/my_strdup.c\
		lib/my_str_isalphanum.c\

TESTS	=	tests/test_minishell.c\
		tests/test_gnl.c

NAME	=	mysh

OBJ	=	$(SRC:.c=.o) $(LIB:.c=.o) $(MAIN:.c=.o)

CFLAGS	=	-I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)


debug:
	gcc -g -o $(NAME) src/main.c $(SRC) -I./include -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o unit_tests $(SRC) $(LIB) $(TESTS) -I./include --coverage -lcriterion
	./unit_tests

cleangc:
	rm *.gcno
	rm *.gcda
