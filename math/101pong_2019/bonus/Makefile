##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make a file
##

SRC	=	src/main.c\
		src/main_screen.c\
		src/pong.c\
		src/pause_menu.c\
		src/game_over.c\
		lib/my_texture_create.c\
		lib/my_texture_destroy.c\
		lib/my_strdup.c\
		lib/my_strlen.c\
		lib/create-destroy/ball.c\
		lib/create-destroy/pad.c\
		lib/create-destroy/text.c\
		lib/create-destroy/background.c\

NAME	=	101pong

OBJ	=	$(SRC:.c=.o)

FLAGS	=	-l csfml-graphics -l csfml-window -l csfml-system

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
