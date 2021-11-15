##
## EPITECH PROJECT, 2019
## 103cipher
## File description:
## makefile
##

MAIN	=	main.c\

SRC	=	src/help.c\
		src/find_key_size.c\
		src/encode.c\
		src/display_matrice.c\
		src/create_tab.c\
		src/multiply_matrice.c\
		src/destroy_tab.c\
		src/decode.c\
		lib/my_strcmp.c\
		lib/my_strlen.c\

TEST	=	tests/test_encode.c

OBJ	=	$(SRC:.c=.o)

NAME	=	103cipher

CFLAGS	=	-l criterion --coverage

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(MAIN) $(SRC) -I./include -lm -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
