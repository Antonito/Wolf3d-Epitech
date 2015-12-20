/*
** parse.c for gfx_wolf3d in /gfx_wolf3d/src/multiplayer
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 20 06:53:09 2015 Antoine Baché
** Last update Sun Dec 20 18:54:50 2015 Antoine Baché
*/

#include "my.h"

void	load_map_info_multi(t_main_menu *menu)
{
 menu->multi.width =
   (char *)bunny_ini_get_field(menu->file, "level1", "width", 0);
  menu->multi.height =
    (char *)bunny_ini_get_field(menu->file, "level1", "height", 0);
  menu->multi.tile =
    (char *)bunny_ini_get_field(menu->file, "level1", "tile_size", 0);
  menu->player.pposx =
    (char *)bunny_ini_get_field(menu->file, "level1", "start_position", 0);
  menu->player.pposy =
    (char *)bunny_ini_get_field(menu->file, "level1", "start_position", 1);
  menu->player.pangle =
    (char *)bunny_ini_get_field(menu->file, "level1", "start_position", 2);
}

int	parse_file_multi(t_main_menu *menu)
{
  load_map_info_multi(menu);
  menu->map_size.width = my_getnbr(menu->multi.width);
  menu->map_size.height = my_getnbr(menu->multi.height);
  menu->map_size.tile = my_getnbr(menu->multi.tile);
  menu->player.posx = my_getnbr(menu->player.pposx);
  menu->player.posy = my_getnbr(menu->player.pposy);
  menu->player.angle = my_getdouble(menu->player.pangle);
  return (0);
}

int	load_ini_multi(t_main_menu *menu)
{
  if (check_ini(menu) == 1)
    return (1);
  if (parse_file_multi(menu) == 1)
    return (1);
  if (parse_file(menu) == 1)
    return (1);
  return (0);
}
