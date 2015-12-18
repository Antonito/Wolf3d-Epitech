/*
** my.h for gfx_wolf3d in /gfx_wolf3d/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 13 00:35:38 2015 Antoine Baché
** Last update Fri Dec 18 21:07:42 2015 Antoine Baché
*/


#ifndef MY_H_
# define MY_H_
# define UNUSED __attribute__((unused))
# define WIN_X 800
# define WIN_Y 600
# define MAIN_TITLE 150
# define SPACE_TITLE 25
# define SUB_TITLE 125
# define SQUARE_SIZE 18
# define MAP_X_OFFSET 2
# define MAP_Y_OFFSET 400
# define ERROR_MAIN_WIN free_on_winerror(menu)
# define ERROR_MAIN_PIX free_on_pixerror(menu)
# define ERROR_MAIN_MUSIC free_on_musicerror(menu)

# include <stdlib.h>
# include <unistd.h>
# include <lapin.h>

typedef struct		s_player
{
  int			posx;
  int			posy;
  double	       	angle;
}			t_player;

typedef struct		s_map_size
{
  int			width;
  int			height;
  int			tile;
}			t_map_size;

typedef struct		s_option_menu
{
  char			select;
  char			music;
}			t_option_menu;

typedef	struct		s_main_menu
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
  t_bunny_music		*music;
  t_bunny_ini		*file;
  t_map_size		map_size;
  char			**map;
  char			select;
  char			toggle_pause;
  t_option_menu		options;
  t_player		player;
}			t_main_menu;

/*
** Minimap (minimap.c)
*/
void			display_minimap(t_main_menu *);

/*
** Load BMP images (load_bmp.c)
*/
unsigned int  		*load_bmp(void);

/*
** Main menu functions (main.c)
*/
t_bunny_response	key(t_bunny_event_state, t_bunny_keysym, t_main_menu *);
t_bunny_response	mainMenuLoop(t_main_menu *);
int			main_menu(void);

/*
** Free on errors main (free_main.c)
*/
int			free_on_winerror(t_main_menu *);
int			free_on_pixerror(t_main_menu *);
int			free_on_musicerror(t_main_menu *);

/*
** Draw Main Menu functions (/menu/main_menu.c)
*/
void			main_title(t_main_menu *);
void			sub_titles(t_main_menu *);
void			put_selector(t_main_menu *);
void			fill_black(t_main_menu *);
void			draw_menu(t_main_menu *);

/*
** Main Menu actions (/menu/main_menu_actions.c)
*/
int			main_menu_actions(t_main_menu *);

/*
** Option menu (/menu/option.c)
*/
t_bunny_response	key_option(t_bunny_event_state,
				   t_bunny_keysym, t_main_menu *);

/*
** Drawn options menu (/menu/option_menu.c)
*/
void			option_title(t_main_menu *);
void			sub_option_titles(t_main_menu *);
void			put_option_selector(t_main_menu *);
void			draw_option_menu(t_main_menu *);

/*
** Option menu actions (/menu/option_menu_actions.c)
*/
int			option_menu_actions(t_main_menu *);
t_bunny_response	OptionMenuLoop(t_main_menu *);
int			option_menu(t_main_menu *);

/*
** Pause menu
*/
int			pause_menu(t_main_menu *);
t_bunny_response	PauseMenuLoop(t_main_menu *);
t_bunny_response	key_pause(t_bunny_event_state,
				  t_bunny_keysym, t_main_menu *);

/*
** Draw pause menu (/menu/pause_menu_draw.c)
*/
void			pause_title(t_main_menu *);
void			sub_pause_titles(t_main_menu *);
void			put_pause_selector(t_main_menu *);
void			draw_pause_menu(t_main_menu *);

/*
** Pause menu action (/menu/pause_menu_actions.c)
*/
int			pause_menu_actions(t_main_menu *);

/*
** Wolf3D start (/wolf/wolf.c)
*/
t_bunny_response	key_wolf(t_bunny_event_state, t_bunny_keysym,
				 t_main_menu *);
void			set_to_black(t_main_menu *);
t_bunny_response	wolfloop(t_main_menu *);
int			wolf(t_main_menu *);

/*
** Check_ini.c
*/
int			check_ini(t_main_menu *);
int			check_field(t_main_menu *);
int			load_ini(t_main_menu *);
int			my_strlen_bis(char *);
int			my_power_ten(int);
int			my_is_neg(char *);
int			my_getnbr(char *);
void			load_map_info(t_main_menu *);

/*
** /wolf/display_wolf.c
*/
void			set_sky(t_main_menu *);
void			display_wolf(t_main_menu *);

/*
** my_getdouble.c
*/
void			remove_comma(char *);
double			my_getdouble(char *);
int			my_power(int, int);

#endif /* !MY_H_ */
