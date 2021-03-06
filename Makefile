##
## Makefile for make in /home/peau_c/#HIDDEN#
##
## Made by Poc
## Login   <peau_c@epitech.net>
##
## Started on  Mon Jan 18 14:44:16 2016 Clement Peau
## Last update Sun Mar 20 20:33:05 2016 Poc
##

RELEASE	=	no

POC	=	yes

SRC	=	srcs/main_prog/get_next_line.c		\
		srcs/main_prog/main.c			\
		sound/src/sound.c			\
		srcs/main_prog/my_list.c		\
		srcs/main_prog/tekfunction.c		\
		srcs/Masque-Damier/dam.c		\
		srcs/Masque-Damier/dam_two.c		\
		srcs/Masque-Damier/events.c		\
		srcs/presentation/events.c		\
		srcs/presentation/tektext.c		\
		srcs/presentation/title.c		\
		srcs/presentation/push.c		\
		srcs/presentation/loop.c		\
		srcs/presentation/tekpixel_int.c	\
		srcs/scroller_wolfs/blit_pictures.c	\
		srcs/scroller_wolfs/events.c		\
		srcs/scroller_wolfs/my_events.c		\
		srcs/scroller_wolfs/moove_wolfs.c	\
		srcs/scroller_wolfs/resize.c		\
		srcs/scroller_wolfs/tekpixel.c		\
		srcs/plasmy/colorplasma.c		\
		srcs/plasmy/fillplasma.c		\
		srcs/plasmy/plasma.c			\
		srcs/plasmy/tekpixelplasma.c		\
		srcs/plasmy/mainplasma.c		\
		srcs/flammy/color.c			\
		srcs/flammy/draw.c			\
		srcs/flammy/fill.c			\
		srcs/flammy/mainflame.c			\
		srcs/flammy/prepare.c			\
		srcs/flammy/draw_scroll_flammy.c	\
		srcs/degrade/events.c			\
		srcs/degrade/degraded.c			\
		srcs/degrade/tekpix.c			\
		srcs/starfield/frontal.c		\
		srcs/starfield/starfield.c		\
		srcs/flag/calc.c			\
		srcs/flag/event.c			\
		srcs/flag/fill.c			\

OBJ	=	$(SRC:.c=.o)

NAME	= 	demo

CMD+=	-lsfml-system -lstdc++ -ldl -L ~/.froot/lib -lm
CMD+=	-llapin -lsfml-audio -lsfml-graphics -lsfml-window

ifeq ($(RELEASE), yes)
	CFLAGS	= -W  -Wall -Wextra -Werror
else
	CFLAGS	= -W -Wall -Wextra -Werror -g -D DEBUG
endif

ifeq ($(POC), yes)
	CC	= 	@ clang -g
else
	CC	=	@ gcc
endif

$(NAME): 	$(OBJ)
		@ tput setaf 2
		@ echo "[OK] > Linking"
		@ echo "Feeding some sweets to the AERs..."
		@ echo "[OK] > Done"
		@ gcc $(OBJ) -o $(NAME) $(CMD) -rdynamic -dsl
		@ echo -e "\033[1;32m \t \t \t ♩♪♫ DEMO\033[0;32m®\033[1;32m Compiled Sucesfully ♩♪♫\033[0m "

all:		 $(NAME)

release:
		@ echo "RELEASE -> $(RELEASE)"

clean:
		@ tput setaf 2
		@ echo "[OK] > Deleting .o"
		@ rm -f $(OBJ)
		@ tput setaf 7

fclean:		clean
		@ tput setaf 2
		@ echo "[OK] > Deleting binaries"
		@ rm -f $(NAME)
		@ tput setaf 7

re:		fclean all

.c.o:
		@ $(CC) -Iinclude/ -c $< -o $@
		@ tput setaf 2
		@ echo -e "[OK] > $<\t\t"
		@ tput setaf 7
