##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make a file
##

SRC	=	src/main.c\
		src/input_tabint.c\
		src/find_best_square.c\
		src/change_tab.c\
		lib/my_getnbr.c\
		lib/my_putstr.c\
		lib/my_strlen.c\
		lib/my_putchar.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
