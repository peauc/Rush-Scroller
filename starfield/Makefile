##
## Makefile for  in /home/peau_c/bin
##
## Made by ~/bin
## Login   <peau_c@epitech.net>
##
## Started on  TEST_FILE
## Last update Sun Mar 20 13:24:10 2016 Clement Peau
##

SRC=	src/main.c 		\
	src/fill.c 		\
	src/starfield.c		\
	src/frontal.c		\
	tekpixel.c	\

OBJ=	$(SRC:.c=.o)

CC=	gcc -g -o $(NAME) $(LIB)

CFLAGS=	-W -Wall -ansi -pedantic -Wextra

CMD=	-llapin -lsfml-audio -lsfml-graphics -lsfml-window
CMD+=	-lsfml-system -lstdc++ -ldl -L ~/.froot/lib -lm

LIB=	-I inc/

NAME=	TEST

$(NAME):	$(OBJ)
		$(CC) $(OBJ) $(CMD)

all:		$(NAME)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
