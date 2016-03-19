##
## Makefile for makeigle in /home/peau_c/rendu/LibLapin/gfx_incendie
##
## Made by
## Login   <peau_c@epitech.net>
##
## Started on  Fri Dec  4 20:13:22 2015
## Last update Fri Mar 18 19:55:52 2016 Clement Peau
##

SRC=	src/mainflame.c \
	src/fill.c \
	src/draw.c \
	src/color.c \
	src/tekpixel.c

SRC2=	src/colorplasma.c \
	src/plasma.c \
	src/mainplasma.c \
	src/fillplasma.c \
	src/tekpixelplasma.c

OBJ=	$(SRC:.c=.o)

OBJ2=	$(SRC2:.c=.o)

NAME2=	plasma

NAME=	incendie

CC=	gcc -g

CFLAGS=	-W -Wall -ansi -pedantic

CMD= -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm -llapin -L ~/.froot/lib

$(NAME):	$(OBJ) $(NAME2)
		gcc -o $(NAME) $(OBJ) $(CMD)

$(NAME2):	$(OBJ2)
		gcc -o $(NAME2) $(OBJ2) $(CMD)

all:		$(NAME2) $(NAME)

clean:
		rm -rf $(OBJ) $(OBJ2)

fclean:		clean
		rm -rf $(NAME) $(NAME2)

re:		fclean all
