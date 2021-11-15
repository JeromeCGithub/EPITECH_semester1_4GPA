##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile of the project.
##

SRC	=	main.c\
		error.c\
		compare_language.c\
		print_language.c\
		find_langage.c\
		lib/my/my_putstr.c\
		lib/my/my_strlen.c\
		lib/my/my_putchar.c\
		lib/my/my_put_nbr.c\
		lib/my/my_strupcase.c\
		lib/my/my_strlowcase.c

OBJ	=	$(SRC:.c=.o)

NAME	=	rush2

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
