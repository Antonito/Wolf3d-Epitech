##
## Makefile for Infographie in /home/bache_a/Infographie
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Mon Nov  2 12:00:40 2015 Antoine Baché
## Last update Tue Jan  5 17:39:28 2016 Antoine Baché
##

DEBUG=		no

SRC=		src/main.c			\
		src/free_main.c			\
		src/parse.c			\
		src/prepare_struct.c		\
		src/my_strcmp.c			\
		src/wolf/wolf.c			\
		src/wolf/check_ini.c		\
		src/wolf/check_pos.c		\
		src/wolf/load_ini.c		\
		src/wolf/my_getnbr.c		\
		src/wolf/display_wolf.c		\
		src/wolf/my_getdouble.c		\
		src/wolf/check_wall.c		\
		src/wolf/player_move.c		\
		src/minimap/minimap.c		\
		src/menu/pause_menu.c		\
		src/menu/pause_menu_draw.c	\
		src/menu/pause_menu_actions.c	\
		src/menu/option.c		\
		src/menu/option_menu.c		\
		src/menu/option_menu_actions.c	\
		src/menu/main_menu_actions.c	\
		src/menu/main_menu.c		\
		src/texture/load_bmp.c		\
		src/texture/main_menu_texture.c	\
		src/texture/opt_menu_texture.c	\
		src/texture/game_menu_texture.c	\
		src/texture/display_wall.c	\
		src/texture/prepare_texture.c	\
		src/multiplayer/my_strdup.c	\
		src/multiplayer/client.c	\
		src/multiplayer/multiplayer.c	\
		src/multiplayer/multi_client.c	\
		src/multiplayer/server.c	\
		src/multiplayer/parse.c		\
		src/multiplayer/my_strlen.c	\
		src/multiplayer/pos.c		\
		src/multiplayer/socket.c

NAME=		wolf3d

HEAD=		-Iinclude

ifeq ($(DEBUG), yes)
		CFLAGS=		$(HEAD) -W -Wall -ansi -pedantic -g
else
		CFLAGS=		$(HEAD) -W -Wall -Werror -ansi -pedantic
endif

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
ifeq ($(DEBUG), yes)
	@tput setaf 1; tput bold
	@echo "  ____  _____ ____  _   _  ____   __  __  ___  ____  _____ ";
	@echo " |  _ \| ____| __ )| | | |/ ___| |  \/  |/ _ \|  _ \| ____|";
	@echo " | | | |  _| |  _ \| | | | |  _  | |\/| | | | | | | |  _|  ";
	@echo " | |_| | |___| |_) | |_| | |_| | | |  | | |_| | |_| | |___ ";
	@echo " |____/|_____|____/ \___/ \____| |_|  |_|\___/|____/|_____|";
	@echo "                                                           ";
	@tput sgr0
endif
	@echo -n "Compiling ..."
	@$(CC) $(OBJ) -o $(NAME) $(LIB)
	@tput setaf 2; tput bold; echo "			OK"
	@tput sgr0


%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

all:	$(NAME)

clean:
	@echo -n "Removing OBJ files ..."
	@$(RM) $(OBJ)
	@tput setaf 2; tput bold; echo "		OK"
	@tput sgr0

fclean:	clean
	@echo -n "Deleting" $(NAME) "..."
	@$(RM) $(NAME)
	@tput setaf 2; tput bold; echo "		OK"
	@tput sgr0

re:	fclean all

.PHONY:	all clean fclean re
