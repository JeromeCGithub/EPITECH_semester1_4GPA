##
## EPITECH PROJECT, 2019
## my_printf
## File description:
## Makefile
##

SRC	=	lib/my/my_put_binary.c\
		lib/my/my_putchar.c\
		lib/my/my_put_real_char.c\
		lib/my/my_put_hexadecimal.c\
		lib/my/my_put_hex.c\
		lib/my/my_putnbr.c\
		lib/my/my_put_octal.c\
		lib/my/my_putstr.c\
		lib/my/my_putunsigned_nbr.c\
		lib/my/my_printf.c\
		lib/my/my_revstr.c\
		lib/my/my_strlen.c\
		lib/my/unstack.c\
		lib/my/my_getnbr.c\
		lib/my/print_string.c\
		lib/my/initptr.c\
		lib/my/find_flags.c

SRCTEST	=	tests/tests_lib.c\
		tests/tests_my_printf.c\
		tests/tests_my_printf2.c\
		tests/tests_my_printf3.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME) cp

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

cp:
	cp libmy.a lib/
	cp libmy.a lib/my

tests_run:	$(OBJ)
	gcc -o unit_tests $(SRC) $(SRCTEST) --coverage -lcriterion
	./unit_tests

cleangc:
	rm *.gcno
	rm *.gcda
