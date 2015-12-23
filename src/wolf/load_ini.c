/*
** load_ini.c for gfx_wolf3d in /gfx_wolf3d/src/wolf
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Dec 17 12:00:38 2015 Antoine Baché
** Last update Wed Dec 23 09:45:34 2015 Antoine Baché
*/

#include "my.h"

void	load_map_info(t_main_menu *data)
{
 data->map_size.width = my_getnbr((char *)bunny_ini_get_field(data->file,
							       "level1",
							       "width", 0));
  data->map_size.height = my_getnbr((char *)bunny_ini_get_field(data->file,
								"level1",
								"height", 0));
  data->map_size.tile = my_getnbr((char *)bunny_ini_get_field(data->file,
							      "level1",
							      "tile_size", 0));
  data->player.posx = my_getnbr((char *)bunny_ini_get_field(data->file,
							    "level1",
							    "start_position",
							    0));
  data->player.posy = data->map_size.height -
    my_getnbr((char *)bunny_ini_get_field(data->file, "level1",
					  "start_position", 1)) - 1;
  data->player.angle =
    my_getdouble((char *)bunny_ini_get_field(data->file, "level1",
					     "start_position", 2));
}

int	load_map(t_main_menu *data)
{
  int	i;
  int	j;

  if ((data->map = bunny_malloc(sizeof(char *) * data->map_size.height))
      == NULL)
    return (1);
  i = -1;
  j = -1;
  while (++i < data->map_size.height)
    if ((data->map[i] = bunny_malloc(data->map_size.width)) == NULL)
      return (1);
  while (++j < data->map_size.height && (i = -1))
    while (++i < data->map_size.width)
      {
	if ((data->map[j][i] =
	     my_getnbr((char *)bunny_ini_get_field(data->file,
						   "level1", "data", i + j *
						   data->map_size.width)))
	    != 0 && data->map[j][i] != 1)
	  return (1);
      }
  return (0);
}

int	parse_file(t_main_menu *data)
{
  load_map_info(data);
  if (load_map(data) == 1)
    return (1);
  return (0);
}

int	load_ini(t_main_menu *data)
{
  if (check_ini(data) == 1)
    return (1);
  if (parse_file(data) == 1)
    return (1);
  if (check_map(data) == 1)
    return (1);
  bunny_delete_ini(data->file);
  return (0);
}
