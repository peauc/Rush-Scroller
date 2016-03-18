##
## Makefile for  in /home/peau_c/bin
##
## Made by ~/bin
## Login   <peau_c@epitech.net>
##
## Started on  TEST_FILE
## Last update Fri Mar 18 19:53:50 2016 Clement Peau
##

SRC=	src/main.c \

OBJ=	$(SRC:.c=.o)

CFLAGS=	-W -Wall -Werror -ansi -pedantic -Wextra -Iinc

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
