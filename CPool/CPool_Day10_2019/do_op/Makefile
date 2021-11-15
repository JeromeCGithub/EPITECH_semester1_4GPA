##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## A makefile for the project.
##

SRC	=	main.c\
		my_get_number_pimped.c\
		my_putchar.c\
		my_put_nbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	do-op

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
