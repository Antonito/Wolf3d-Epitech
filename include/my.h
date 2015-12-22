/*
** my.h for gfx_wolf3d in /gfx_wolf3d/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 13 00:35:38 2015 Antoine Baché
** Last update Tue Dec 22 19:07:57 2015 Antoine Baché
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
# define GROUND_COLOR 0x838383
# define SKY_COLOR 0xFF8D55
# define PLAYER_COLOR 0x22F1FF
# define ERROR_MAIN_WIN free_on_winerror(menu)
# define ERROR_MAIN_PIX free_on_pixerror(menu)
# define ERROR_MAIN_MUSIC free_on_musicerror(menu)
# define PACKED __attribute__((packed))
# define ABS(x) ((x < 0) ? -x : x)
# define BUFF_SIZE 4096
# define WALL_COLOR 0xCF3EFC

# include <sys/socket.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <lapin.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct		s_infos
{
  char			*pseudo;
  char			*address;
  int			port;
  char			*map;
}			t_infos;

typedef struct	       	s_bmp_info_header
{
  PACKED unsigned int	struct_size;
  PACKED int		width;
  PACKED int		height;
  PACKED unsigned short	colorplanes;
  PACKED unsigned short	bit_per_pixel;
  PACKED unsigned int	compression;
  PACKED unsigned int	byte_size;
  PACKED int		pix_per_meter_x;
  PACKED int		pix_per_meter_y;
  PACKED unsigned int	nb_color_used;
  PACKED unsigned int	nb_color_important;
}			t_bmp_info_header;

typedef struct		s_bmp_header
{
  PACKED unsigned short	type;
  PACKED unsigned int	size;
  PACKED unsigned int	reserved1;
  PACKED unsigned int	offset;
}			t_bmp_header;

typedef struct		s_texture
{
  unsigned int		**picture;
  int			width;
  int			height;
  t_bmp_header		head;
  t_bmp_info_header	info;
}			t_texture;

typedef struct		s_vector
{
  double		x;
  double		y;
}			t_vector;

typedef struct		s_player
{
  double		posx;
  double		posy;
  double	       	angle;
  double		oldposx;
  double		oldposy;
  char			*pseudo;
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

typedef struct		s_multiplayer
{
  int			serv_fd;
  int			client_fd;
  char			*width;
  char			*height;
  char			*tile;
}			t_multiplayer;

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
  t_texture		**texture;
  t_option_menu		options;
  t_player		player;
  t_player		player2;
  t_multiplayer		multi;
  t_infos		infos;
  int			game_mode;
}			t_main_menu;

/*
** Minimap (minimap.c)
*/
void			display_minimap(t_main_menu *);

/*
** Load BMP images (load_bmp.c)
*/
int			load_bmp(t_texture *, char *);
void			display_bmp(t_main_menu *, int, int, int);
void			display_reversed_bmp(t_main_menu *, int, int, int);
int			main_menu_texture(t_main_menu *);
void			main_menu_texture_disp(t_main_menu *);
int			option_menu_texture(t_main_menu *);
void			option_menu_texture_disp(t_main_menu *);
int			pause_menu_texture(t_main_menu *);
void			pause_menu_texture_disp(t_main_menu *);
int			game_texture(t_main_menu *);
void			display_texture_wall(t_main_menu *, double, int);
int			bmp_error(void);
int			prepare_texture(t_main_menu *);

/*
** Main menu functions (main.c)
*/
t_bunny_response	key(t_bunny_event_state, t_bunny_keysym, t_main_menu *);
t_bunny_response	mainMenuLoop(t_main_menu *);
int			main_menu(t_main_menu *);

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
void			sub_pause_titles(t_main_menu *);
void			put_pause_selector(t_main_menu *);
void			draw_pause_menu(t_main_menu *);
void			fill_black_alpha(t_main_menu *);

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
int			parse_file(t_main_menu *);
int			check_field(t_main_menu *);
int			load_ini(t_main_menu *);
int			my_strlen_bis(char *);
int			my_power_ten(int);
int			my_is_neg(char *);
int			my_getnbr(char *);
void			load_map_info(t_main_menu *);
int			check_map(t_main_menu *);
int			load_map(t_main_menu *);
int			checck_map_border(t_main_menu *);
int			check_pos(t_main_menu *);

/*
** /wolf/display_wolf.c
*/
void			set_sky(t_main_menu *);
void			display_wolf(t_main_menu *);

/*
** my_getdouble.c
*/
void			remove_comma(char *, char *);
double			my_getdouble(char *);
int			my_power(int, int);

/*
** check_wall
*/
void			check_wall(t_main_menu *);
void			get_vector_pos(t_vector *, int, double);
void			get_wall_pos(t_vector *, t_main_menu *, int);
void			display_wall(t_main_menu *, double, int);

/*
** player_move.c
*/
void			rotate_player(t_bunny_keysym, t_main_menu *);
void			move_player(t_bunny_keysym, t_main_menu *);
int			check_collision(t_main_menu *, char);
int			check_collision_x(t_main_menu *, char);
int			check_collision_y(t_main_menu *, char);

/*
** Server
*/
int			socket_send(int, char *);
char			*socket_read(int);
int			my_strlen(char *);
int			server(int);
int			bind_serv(struct sockaddr_in *, int, int);
int			client(char *, int);
char			*socket_read(int);

/*
** Parsing
*/
void			prepare_infos(t_infos *);
void			parse_client(char **, t_infos *);
void			parse_serv(char **, t_infos *);
int			parse_args(int, char **, t_infos *);
int			usage_message(void);
t_main_menu		*prepare_main(void);
int			my_strcmp(char *, char *);

/*
** Multiplayer
*/
int			start_multiplayer(t_main_menu *);
int			start_client(t_main_menu *);
int			start_server(t_main_menu *);
int			load_ini_multi(t_main_menu *);
int			parse_file_multi(t_main_menu *);
void			load_map_info_multi(t_main_menu *);
int			client_map(t_main_menu *);
int			server_map(t_main_menu *);
int			socket_send_map(int, char *, int);
void			display_player(t_main_menu *, double, int);
void			calc_pos_player(t_main_menu *);
void			server_pos(t_main_menu *);
void			client_pos(t_main_menu *);
char			*my_strdup(char *);
int			client_map_basics(t_main_menu *);
int			client_distant_player(t_main_menu *);
double			socket_r_double(int);
int			socket_send_double(int, double);
void			set_player_pos(t_main_menu *);
int			serv_distant_player(t_main_menu *);
void			set_client_position(t_main_menu *);
int			check_pos_distant(t_main_menu *);
void			free_texture(t_texture *);
void			set_max_heap_size(size_t);

#endif /* !MY_H_ */
