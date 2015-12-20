/*
** load_ini.c for gfx_wolf3d in /gfx_wolf3d/src/wolf
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Dec 17 12:00:38 2015 Antoine Baché
** Last update Sun Dec 20 09:12:14 2015 Antoine Baché
*/

#include "my.h"

void	load_map_info(t_main_menu *menu)
{
 menu->map_size.width = my_getnbr((char *)bunny_ini_get_field(menu->file,
							       "level1",
							       "width", 0));
  menu->map_size.height = my_getnbr((char *)bunny_ini_get_field(menu->file,
								"level1",
								"height", 0));
  menu->map_size.tile = my_getnbr((char *)bunny_ini_get_field(menu->file,
							      "level1",
							      "tile_size", 0));
  menu->player.posx = my_getnbr((char *)bunny_ini_get_field(menu->file,
							    "level1",
							    "start_position",
							    0));
  menu->player.posy = menu->map_size.height -
    my_getnbr((char *)bunny_ini_get_field(menu->file, "level1",
					  "start_position", 1)) - 1;
  menu->player.angle =
    my_getdouble((char *)bunny_ini_get_field(menu->file, "level1",
					     "start_position", 2));
}

int	parse_file(t_main_menu *menu)
{
  int	i;
  int	j;

  load_map_info(menu);
  if ((menu->map = bunny_malloc(sizeof(char *) * menu->map_size.height))
      == NULL)
    return (1);
  i = -1;
  j = -1;
  while (++i < menu->map_size.height)
    if ((menu->map[i] = bunny_malloc(menu->map_size.width)) == NULL)
      return (1);
  while (++j < menu->map_size.height && (i = -1))
    while (++i < menu->map_size.width)
      {
	if ((menu->map[j][i] =
	     my_getnbr((char *)bunny_ini_get_field(menu->file,
						   "level1", "data", i + j *
						   menu->map_size.width)))
	    != 0 && menu->map[j][i] != 1)
	  return (1);
      }
  return (0);
}

int	load_ini(t_main_menu *menu)
{
  if (check_ini(menu) == 1)
    return (1);
  if (parse_file(menu) == 1)
    return (1);
  return (0);
}
