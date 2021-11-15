##
## EPITECH PROJECT, 2019
## 103cipher
## File description:
## makefile
##

MAIN	=	main.c\

SRC	=	src/help.c\
		src/sphere.c\
		src/display_delta.c\
		src/error_handling.c\
		src/cylinder.c\
		src/cone.c\
		src/find.c\
		lib/my_strcmp.c\

TEST	=	tests/test_encode.c

OBJ	=	$(SRC:.c=.o)

NAME	=	104intersection

CFLAGS	=	-l criterion --coverage

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(MAIN) $(SRC) -I./include -lm -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
