##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make a file
##

SRC	=	main.c\
		my_putstr.c\
		my_putchar.c\
		check_square.c\
		my_put_nbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	rush3

all:	$(OBJ)
	gcc -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
