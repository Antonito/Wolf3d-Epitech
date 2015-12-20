##
## Makefile for Infographie in /home/bache_a/Infographie
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Mon Nov  2 12:00:40 2015 Antoine Baché
## Last update Sun Dec 20 05:16:09 2015 Antoine Baché
##

SRC=		src/main.c			\
		src/free_main.c			\
		src/load_bmp.c			\
		src/parse.c			\
		src/prepare_struct.c		\
		src/my_strcmp.c			\
		src/wolf/wolf.c			\
		src/wolf/minimap.c		\
		src/wolf/check_ini.c		\
		src/wolf/load_ini.c		\
		src/wolf/my_getnbr.c		\
		src/wolf/display_wolf.c		\
		src/wolf/my_getdouble.c		\
		src/wolf/check_wall.c		\
		src/wolf/player_move.c		\
		src/menu/pause_menu.c		\
		src/menu/pause_menu_draw.c	\
		src/menu/pause_menu_actions.c	\
		src/menu/option.c		\
		src/menu/option_menu.c		\
		src/menu/option_menu_actions.c	\
		src/menu/main_menu_actions.c	\
		src/menu/main_menu.c		\
		src/multiplayer/client.c	\
		src/multiplayer/server.c	\
		src/multiplayer/my_strlen.c	\
		src/multiplayer/socket.c

NAME=		wolf3d

HEAD=		-Iinclude

CFLAGS=		$(HEAD) -W -Wall -Werror -ansi -pedantic -g

CC=		gcc

RM=		rm -f

LIB=		-L/usr/local/lib		\
		-L/home/${USER}/.froot/lib	\
		-I/home/${USER}/.froot/include	\
		-llapin				\
		-lsfml-audio			\
		-lsfml-graphics			\
		-lsfml-window			\
		-lsfml-system			\
		-lstdc++ -ldl			\
		-lm

OBJ=		$(SRC:.c=.o)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
