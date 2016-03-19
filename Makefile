##
## Makefile for makefile in /home/wery_p/rendu/gfx_scroller
##
## Made by Paul Wery
## Login   <wery_p@epitech.net>
##
## Started on  Sat Mar 19 00:33:08 2016 Paul Wery
## Last update Sat Mar 19 01:06:50 2016 Paul Wery
##

NAME	=	démo

RM	=	rm -f

CC	=	gcc

CFLAGS	=	-W -Wall -Werror -Iinclude -I/home/${USER}/.froot/include

LIB	=	-L/home/${USER}/.froot/lib -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm

OBJS	=	$(SRCS:.c=.o)

SRCS	=	srcs/main_prog/main.c \
		srcs/main_prog/my_list.c \
		srcs/main_prog/get_next_line.c \
		srcs/main_prog/tekfunction.c \

$(NAME)	:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) -dsl -rdynamic $(LIB)

all	:	$(NAME)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
