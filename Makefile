##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Make printf
##

CC=gcc

CFLAGS=-Wno-implicit -Wall -Wextra

C_FILES =	src/main.c \
			src/add.c \
			src/del.c \
			src/sort.c

O_FILES = $(C_FILES:.c=.o)

TESTS =

NAME=	organized

$(NAME): lib/libmy.a $(O_FILES)
	cp lib/libmy.a $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(C_FILES) lib/libmy.a shell/libshell.a -g

all: $(NAME)

clean:
	rm -f $(O_FILES) test_$(NAME)
	make -C lib/my clean

fclean: clean
	rm -f $(NAME)
	make -C lib/my fclean

re: fclean all

lib/libmy.a:
	make -C lib/my/

unit_tests: $(NAME)
	$(CC) $(CFLAGS) -o tests.out $(TESTS) $(NAME) -lcriterion

tests_run: fclean unit_tests
	./tests.out

.PHONY: all clean fclean re tests_run
