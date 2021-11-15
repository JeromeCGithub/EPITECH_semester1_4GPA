##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make a file
##

SRC	=	main.c\
		to_npi.c\
		calc.c\
		init_var.c\
		lib/do_op.c\
		lib/is_function.c\
		lib/is_operand.c\
		lib/my_getnbr.c\
		lib/my_putchar.c\
		lib/my_putnbr.c\
		lib/my_strlen.c\
		lib/op_procedure.c

OBJ	=	$(SRC:.c=.o)

NAME	=	eval_expr

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
