##
## Makefile for  in /home/peau_c/bin
##
## Made by ~/bin
## Login   <peau_c@epitech.net>
##
## Started on  TEST_FILE
## Last update Sat Mar 19 18:32:01 2016 Clement Peau
##

SRC=	src/main.c 		\
	src/sound.c 		\

OBJ=	$(SRC:.c=.o)

CC=	clang -g -o $(NAME) $(LIB)

CFLAGS=	-W -Wall  -Wextra

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
