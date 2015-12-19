/*
** player_move.c for gfx_wolf3d in /gfx_wolf3d/src/wolf
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Dec 19 03:43:23 2015 Antoine Baché
** Last update Sat Dec 19 17:52:30 2015 Antoine Baché
*/

#include "my.h"

int		check_collision(t_main_menu *data, char select)
{
  double	tmp_x;
  double	tmp_y;

  if (select == 0)
    {
      tmp_x = data->player.posx - 0.1 * cos((data->player.angle * M_PI) / 180);
      tmp_y = data->player.posy - 0.1 * sin((data->player.angle * M_PI) / 180);
    }
  else
    {
      tmp_x = data->player.posx + 0.1 * cos((data->player.angle * M_PI) / 180);
      tmp_y = data->player.posy + 0.1 * sin((data->player.angle * M_PI) / 180);
    }
  if (data->map[data->map_size.width - (int)tmp_x - 1]
      [data->map_size.height - (int)tmp_y - 1] != 0)
    return (1);
  return (0);
}

void	move_player(t_bunny_keysym key, t_main_menu *data)
{
  if (key == BKS_DOWN && data->map_size.height > (int)data->player.posy &&
      data->map_size.width > (int)data->player.posx &&
      check_collision(data, 0) == 0)
    {
      data->player.posx -= 0.1 * cos((data->player.angle * M_PI) / 180);
      data->player.posy -= 0.1 * sin((data->player.angle * M_PI) / 180);
    }
  else if (key == BKS_UP && 0 < (int)data->player.posy &&
	   0 < (int)data->player.posx && check_collision(data, 1) == 0)
    {
      data->player.posx += 0.1 * cos((data->player.angle * M_PI) / 180);
      data->player.posy += 0.1 * sin((data->player.angle * M_PI) / 180);
    }
}

void	rotate_player(t_bunny_keysym key, t_main_menu *data)
{
  if (key == BKS_RIGHT)
    data->player.angle -= 3;
  else
    data->player.angle += 3;
}
