##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make a file
##

SRC	=	src/evalexpr/evalexpr.c\
		src/main.c\
		src/print_h.c\
		src/error_malloc.c\
		src/error_handling.c\
		src/syntax_error.c\
		src/evalexpr/error_less.c\
		src/evalexpr/to_npi.c\
		src/evalexpr/calc.c\
		src/evalexpr/init_var.c\
		src/calcinf/addinf.c\
		src/calcinf/subinf.c\
		src/calcinf/mutinf.c\
		src/calcinf/divinf.c\
		src/calcinf/modinf.c\
		src/convertbase/clean_str.c\
		src/convertbase/reconvert.c\
		src/convertbase/convert_base.c\
		lib/do_op.c\
		lib/catncat.c\
		lib/my_nbtostr.c\
		lib/my_memset.c\
		lib/my_strndup.c\
		lib/my_strdup.c\
		lib/my_nbcmp.c\
		lib/my_strncat.c\
		lib/my_getnbr.c\
		lib/my_revstr.c\
		lib/my_putstr.c\
		lib/is_function.c\
		lib/is_operand.c\
		lib/my_putchar.c\
		lib/my_putnbr.c\
		lib/my_strlen.c\
		lib/op_procedure.c

SRCFORTEST	=	src/evalexpr/evalexpr.c\
		src/print_h.c\
		src/error_malloc.c\
		src/error_handling.c\
		src/syntax_error.c\
		src/evalexpr/error_less.c\
		src/evalexpr/to_npi.c\
		src/evalexpr/calc.c\
		src/evalexpr/init_var.c\
		src/calcinf/addinf.c\
		src/calcinf/subinf.c\
		src/calcinf/mutinf.c\
		src/calcinf/divinf.c\
		src/calcinf/modinf.c\
		src/convertbase/reconvert.c\
		src/convertbase/clean_str.c\
		src/convertbase/convert_base.c\
		lib/do_op.c\
		lib/catncat.c\
		lib/my_nbtostr.c\
		lib/my_memset.c\
		lib/my_strndup.c\
		lib/my_strdup.c\
		lib/my_nbcmp.c\
		lib/my_strncat.c\
		lib/my_getnbr.c\
		lib/my_revstr.c\
		lib/my_putstr.c\
		lib/is_function.c\
		lib/is_operand.c\
		lib/my_putchar.c\
		lib/my_putnbr.c\
		lib/my_strlen.c\
		lib/op_procedure.c

SRCTEST	=	tests/tests_evalexpr.c\
		tests/tests_evalexpr2.c\
		tests/tests_redir1.c\
		tests/tests_redir2.c\
		tests/tests_redir3.c\
		tests/tests_redir4.c\
		tests/tests_redir5.c\
		tests/tests_redir6.c\
		tests/tests_convertbase.c\
		tests/tests_lib.c

OBJ	=	$(SRC:.c=.o)

NAME	=	calc

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

tests_run:	$(OBJ)
	gcc -o unit_tests $(SRCFORTEST) $(SRCTEST) --coverage -lcriterion
	./unit_tests

cleangc:
	rm *.gcda
	rm *.gcno
