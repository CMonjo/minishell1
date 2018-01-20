##
## EPITECH PROJECT, 2017
## Project =pname=
## File description:
## Build =pname= binary.
##

CC	=	gcc

CFLAGS	=	-Wextra -W -Wall -I ./include/

LIB	=	-L lib/tools/ -ltools

SRC	=	src/env_handling.c	\
		src/check_imput.c	\
		src/get_env.c		\
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/tools/
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)
	rm -f $(OBJ)
	make clean -C ./lib/tools/

clean:
	rm -f $(OBJ)
	make clean -C ./lib/tools/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/tools/

re: fclean all
