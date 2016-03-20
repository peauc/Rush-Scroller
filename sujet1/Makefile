##
## Makefile for  in /home/peau_c/rendu/Lib/gfx_wolf3d
##
## Made by
## Login   <peau_c@epitech.net>
##
## Started on  Sun Dec 20 16:11:08 2015
## Last update Thu Jan 14 02:25:26 2016 
##

SRC=	src/main.c \
	src/calc.c \
	src/tekpixel.c \
	src/fill.c \

OBJ=	$(SRC:.c=.o)

CC=	gcc -g -lm -L ~/.froot/lib -I ./inc

CFLAGS=	-W -Wall -ansi -pedantic -Werror

RM=	rm -rf

CMD=	-llapin -lsfml-audio -lsfml-graphics -lsfml-window
CMD+=	-lsfml-system -lstdc++ -ldl

NAME=	rohan

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CMD)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
