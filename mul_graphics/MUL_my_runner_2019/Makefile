##
## EPITECH PROJECT, 2019
## my_runner
## File description:
## Makefile
##

SRC	=	src/main.c\
		src/init_background.c\
		src/manage_bg_moove.c\
		src/manage_map.c\
		src/manage_input.c\
		src/victory_souris.c\
		src/pause_souris_move.c\
		src/save_score.c\
		src/collision.c\
		src/load_score.c\
		src/pause_menu.c\
		src/menu.c\
		src/manage_obs_move.c\
		src/victory.c\
		src/destroy.c\
		src/resize_manager.c\
		src/game_over.c\
		src/input_menu.c\
		src/manage_score.c\
		src/game.c\
		src/manage_bird.c\
		src/menu_souris_move.c\
		src/find_high_nb.c\
		src/init_menu.c\
		src/init_player.c\
		lib/delete_node.c\
		lib/check_env.c\
		lib/my_strdup.c\
		lib/next_map.c\
		lib/convert_to_window.c\
		lib/create_text.c\
		lib/my_revstr.c\
		lib/load_music.c\
		lib/my_putstr.c\
		lib/my_putchar.c\
		lib/my_strlen.c\
		lib/my_atoi.c

NAME	=	my_runner

OBJ	=	$(SRC:.c=.o)

FLAGS	=	-l csfml-window -l csfml-system -l csfml-audio -lcsfml-graphics -lm

all:	$(NAME)

$(NAME):
	gcc -g -o $(NAME) $(SRC) -I./include $(FLAGS) -Wall

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
