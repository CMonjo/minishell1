##
## EPITECH PROJECT, 2017
## Project =pname=
## File description:
## Build =pname= binary.
##

CC	=	gcc

CFLAGS	=	-Werror -Wextra -W -Wall -I ./include/

LIB	=	-L lib/my/ -lmy

SRC	=	src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my/
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)
	rm -f $(OBJ)
	make clean -C ./lib/my/

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my/

re: fclean all
