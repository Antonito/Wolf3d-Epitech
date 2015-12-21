/*
** check_ini.c for gfx_wolf3d in /gfx_wolf3d/src/wolf
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Dec 17 12:02:32 2015 Antoine Baché
** Last update Mon Dec 21 08:57:12 2015 Antoine Baché
*/

#include "my.h"

int	check_map_border(t_main_menu *data)
{
  int	i;

  i = -1;
  while (++i < data->map_size.width)
    if (data->map[0][i] != 1 || data->map[data->map_size.height - 1][i] != 1)
      {
	write(2, "./wolf3d: missing map borders\n", 30);
	return (1);
      }
  i = -1;
  while (++i < data->map_size.height)
    if (data->map[i][0] != 1 || data->map[i][data->map_size.width - 1] != 1)
      {
	write(2, "./wolf3d: missing map borders\n", 30);
	return (1);
      }
  return (0);
}

int	check_map(t_main_menu *data)
{
  if (check_map_border(data) == 1)
    return (1);
  if (check_pos(data) == 1)
    return (1);
  return (0);
}

int	check_field(t_main_menu *data)
{
  if (bunny_ini_get_field(data->file, "level1", "data", 0) == NULL)
    {
      write(2, "./wolf3d: missing data field\n", 29);
      return (1);
    }
  else if (bunny_ini_get_field(data->file, "level1", "start_position", 0)
	   == NULL)
    {
      write(2, "./wolf3d: missing start_position field\n", 39);
      return (1);
    }
  else if (bunny_ini_get_field(data->file, "level1", "tile_size", 0)
	   == NULL)
    {
      write(2, "./wolf3d: missing tile_size field\n", 29);
      return (1);
    }
  return (0);
}

int	check_ini(t_main_menu *data)
{
  if ((data->file = bunny_load_ini(data->infos.map)) == NULL)
    {
      write(2, "./wolf3d: cannot open or read file data/map.ini.\n", 49);
      return (1);
    }
  else if (bunny_ini_get_field(data->file, "level1", "width", 0) == NULL)
    {
       write(2, "./wolf3d: incorrect map format\n", 31);
       return (1);
    }
  else if (bunny_ini_get_field(data->file, "level1", "height", 0) == NULL)
    {
      write(2, "./wolf3d: missing height field\n", 31);
      return (1);
    }
  else if (check_field(data) == 1)
    return (1);
  return (0);
}
