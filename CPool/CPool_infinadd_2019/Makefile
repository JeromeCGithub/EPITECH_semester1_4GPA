##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## A makefile for the project.
##

SRC	=	main.c\
		subinf.c\
		my_supnbr.c\
		inputt.c\
		zero_fix_problem.c\
		lib/my/my_rev_list.c\
		lib/my/my_strlen.c\
		lib/my/my_params_to_list.c\
		lib/my/my_putchar.c\
		lib/my/my_display_list.c

OBJ	=	$(SRC:.c=.o)

NAME	=	infin_add

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -ggdb -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
