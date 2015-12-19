/*
** player_move.c for gfx_wolf3d in /gfx_wolf3d/src/wolf
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Dec 19 03:43:23 2015 Antoine Baché
** Last update Sat Dec 19 06:30:43 2015 Antoine Baché
*/

#include "my.h"

void	move_player(t_bunny_keysym key, t_main_menu *data)
{
  if (key == BKS_DOWN && data->map_size.height > (int)data->player.posy &&
      data->map_size.width > (int)data->player.posx)
    {
      data->player.posx -= 0.05 * cos((data->player.angle * M_PI) / 180);
      data->player.posy -= 0.05 * sin((data->player.angle * M_PI) / 180);
    }
  else if (key == BKS_UP && 0 < (int)data->player.posy &&
	   0 < (int)data->player.posx)
    {
      data->player.posx += 0.05 * cos((data->player.angle * M_PI) / 180);
      data->player.posy += 0.05 * sin((data->player.angle * M_PI) / 180);
    }
}

void	rotate_player(t_bunny_keysym key, t_main_menu *data)
{
  if (key == BKS_RIGHT)
    data->player.angle -= 10;
  else
    data->player.angle += 10;
}
