##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make
##

SRC	=	btree_create_node.c

OBJ	=	$(SRC:.c=.o)

CPPFLAGS	=	-I./include

NAME	=	libbtree.a

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(SRC) $(CPPFLAGS)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
