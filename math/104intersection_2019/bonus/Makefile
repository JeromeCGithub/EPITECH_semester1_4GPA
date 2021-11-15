##
## EPITECH PROJECT, 2019
## bonus
## File description:
## Makefile
##

SRC	=	main.c\
		rays.c\
		pt.c\
		dist.c\
		intersect.c\
		vertex_array.c\
		walls.c\
		display.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	ray_casting

FLAGS	=	-l csfml-window -l csfml-graphics -I./include -lm

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
