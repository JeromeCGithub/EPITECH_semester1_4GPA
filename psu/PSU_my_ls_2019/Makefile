##
## EPITECH PROJECT, 2019
## my ls
## File description:
## Makefile
##

SRC	=	src/my_ls.c\
		src/listing.c\
		src/take_flags.c\
		src/display_perm.c\
		src/print_time.c\
		src/display_ll.c\
		src/readlink_d.c\
		src/big_r_flag_manage.c\
		src/sort.c\
		src/sort_r.c\
		src/display_owner_user.c\
		lib/my_putstr.c\
		lib/my_list_size.c\
		lib/my_strcmp.c\
		lib/my_put_nbr.c\
		lib/my_strdup.c\
		lib/my_strlowcase.c\
		lib/my_putchar.c\
		lib/my_strlen.c\
		lib/my_strcat.c\
		lib/insert.c

TESTS	=	tests/test_ls.c\
		tests/test_ls2.c\

NAME	=	my_ls

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):
	gcc -g -o $(NAME) src/main.c $(SRC) -I./include

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o unit_tests $(SRC) $(TESTS) -I./include --coverage -lcriterion
	./unit_tests

cleangc:
	rm *.gcno
	rm *.gcda
