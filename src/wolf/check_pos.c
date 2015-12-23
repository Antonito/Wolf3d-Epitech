/*
** check_pos.c for gfx_wolf3d in /gfx_wolf3d/src/wolf
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Dec 21 08:56:40 2015 Antoine Baché
** Last update Wed Dec 23 12:59:37 2015 Antoine Baché
*/

#include "my.h"

int	check_pos(t_main_menu *data)
{
  if ((int)data->player.posx < 0 ||
      (int)data->player.posx >= data->map_size.width ||
      (int)data->player.posy < 0 ||
      (int)data->player.posy >= data->map_size.height ||
      data->map[data->map_size.height - (int)data->player.posx - 1]
      [data->map_size.width - (int)data->player.posy - 1] == 1)
    {
      write(2, "./wolf3d: incorrect player position\n", 36);
      if (data->game_mode == 2)
	{
	  write(2, "./wolf3d: incorrect distant player position\n", 44);
	  write(2, "Please, ", 8);
	  write(2, "make sure there is a free space at the opposite of ", 51);
	  write(2, data->player2.pseudo, my_strlen(data->player2.pseudo));
	  write(2, ".\n", 2);
	}
      return (1);
    }
  return (0);
}

int	check_pos_distant(t_main_menu *data)
{
  if ((int)data->player2.posx < 0 ||
      (int)data->player2.posx >= data->map_size.width ||
      (int)data->player2.posy < 0 ||
      (int)data->player2.posy >= data->map_size.height ||
      data->map[data->map_size.height - (int)data->player2.posx - 1]
      [data->map_size.width - (int)data->player2.posy -1] == 1)
    {
      write(2, "./wolf3d: incorrect distant player position\n", 44);
      write(2, "Please, ", 8);
      write(2, "make sure there is a free space at the opposite of ", 51);
      write(2, "your position.\n", 15);
      return (1);
    }
  return (0);
}
