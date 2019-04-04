##
## EPITECH PROJECT, 2018
## My Makefile
## File description:
## makefile
##

SRC	=	./src/main.c			\
		./src/tools.c			\
		./src/get_cmd.c			\
		./src/get_argv.c		\
		./src/env_cmd.c			\
		./src/env_check_var.c	\
		./src/cd_cmd.c			\
		./src/exit_cmd.c		\
		./src/find_cmd.c		\
		./src/miniloop.c		\
		./src/free.c			\
		./src/prompt.c			\
		./lib/get_char_pos.c	\
		./lib/my_copycat.c		\
		./lib/my_memcmp.c		\
		./lib/my_putchar.c		\
		./lib/my_putstr.c		\
		./lib/my_strcpy.c		\
		./lib/my_strdup.c		\
		./lib/my_puterror.c		\
		./lib/my_strlen.c		\
		./lib/my_tabledup.c		\
		./lib/my_getnbr.c		\
		./lib/my_put_err_nbr.c	\
		./lib/my_putchar_err.c	\
		./lib/my_nisnum.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -g
CFLAGS	+= -I include

NAME	=	mysh

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

all:    $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean re fclean