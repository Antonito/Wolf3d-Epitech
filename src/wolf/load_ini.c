/*
** load_ini.c for gfx_wolf3d in /gfx_wolf3d/src/wolf
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Dec 17 12:00:38 2015 Antoine Baché
** Last update Thu Dec 17 15:15:13 2015 Antoine Baché
*/

#include "my.h"

int	parse_file(t_main_menu *menu)
{
  int	i;

  menu->map_size.width = my_getnbr((char *)bunny_ini_get_field(menu->file,
							       "level1",
							       "width", 0));
  menu->map_size.height = my_getnbr((char *)bunny_ini_get_field(menu->file,
								"level1",
								"height", 0));
  if ((menu->map = malloc(menu->map_size.width * menu->map_size.height + 1))
      == NULL)
    return (1);
  i = -1;
  while (bunny_ini_get_field(menu->file, "level1", "data", ++i) != NULL)
    {
      if ((menu->map[i] = my_getnbr((char *)
				    bunny_ini_get_field(
							menu->file, "level1",
							"data", i))) != 0 &&
	  menu->map[i] != 1)
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
