/*
** parse.c for gfx_wolf3d in /gfx_wolf3d/src/multiplayer
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 20 06:53:09 2015 Antoine Baché
** Last update Wed Dec 23 09:31:30 2015 Antoine Baché
*/

#include "my.h"

void	load_map_info_multi(t_main_menu *data)
{
 data->multi.width =
   (char *)bunny_ini_get_field(data->file, "level1", "width", 0);
  data->multi.height =
    (char *)bunny_ini_get_field(data->file, "level1", "height", 0);
  data->multi.tile =
    (char *)bunny_ini_get_field(data->file, "level1", "tile_size", 0);
}

int	parse_file_multi(t_main_menu *data)
{
  load_map_info_multi(data);
  data->map_size.width = my_getnbr(data->multi.width);
  data->map_size.height = my_getnbr(data->multi.height);
  data->map_size.tile = my_getnbr(data->multi.tile);
  return (0);
}

int	load_ini_multi(t_main_menu *data)
{
  if (check_ini(data) == 1)
    {
      write(2, "./wolf3d: Error checking .ini\n", 30);
      return (1);
    }
  if (parse_file_multi(data) == 1)
    {
      write(2, "./wolf3d: Error checking .ini\n", 30);
      return (1);
    }
  if (parse_file(data) == 1)
    {
      write(2, "./wolf3d: Error checking .ini\n", 30);
      return (1);
    }
  return (0);
}
