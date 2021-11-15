##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make a file
##

SRC	=	my_cat.c\
		my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	cat

all:	$(OBJ)
	gcc -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
