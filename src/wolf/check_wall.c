/*
** check_wall.c for gfx_wolf3d in /gfx_wolf3d/src/wolf
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Dec 18 23:43:29 2015 Antoine Baché
** Last update Mon Dec 21 11:50:32 2015 Antoine Baché
*/

#include "my.h"

void		display_player(t_main_menu *data, double k, int i)
{
  int		demi_wall;
  int		start;
  int		end;
  t_color	*colors;

  demi_wall = WIN_Y / (2 * k);
  start = WIN_X * (WIN_Y / 2) + i - (WIN_X * demi_wall);
  end = WIN_X * (WIN_Y / 2) + i + (WIN_X * demi_wall);
  colors = data->pix->pixels;
  while (start < end && start >= 0 && end < WIN_X * WIN_Y)
    {
      colors[start].full = PLAYER_COLOR;
      start += WIN_X;
    }
}

void		display_wall(t_main_menu *data, double k, int i)
{
  int		demi_wall;
  int		start;
  int		end;
  t_color	*colors;

  demi_wall = WIN_Y / (2 * k);
  start = WIN_X * (WIN_Y / 2) + i - (WIN_X * demi_wall);
  end = WIN_X * (WIN_Y / 2) + i + (WIN_X * demi_wall);
  colors = data->pix->pixels;
  while (start < end && start >= 0 && end < WIN_X * WIN_Y)
    {
      colors[start].full = 0xCF3EFC;
      start += WIN_X;
    }
}

void		get_wall_pos(t_vector *vec, t_main_menu *data, int i)
{
  double	x;
  double	y;
  double	k;

  k = 0;
  x = 0;
  y = 0;
  while ((int)x < data->map_size.height && (int)y < data->map_size.width)
    {
      x = data->player.posx + (k * vec->x);
      y = data->player.posy + (k * vec->y);
      if (data->map[data->map_size.height - (int)x - 1]
	  [data->map_size.width - (int)y - 1] == 1 && k >= 1)
	{
	  display_wall(data, k, i);
	  break;
	}
      if (data->map[data->map_size.height - (int)x - 1]
	  [data->map_size.width - (int)y - 1] == 2 && k >= 1)
	{
	  display_player(data, k, i);
	  break;
	}
      k += 0.001;
    }
}

void		get_vector_pos(t_vector *vec, int i, double angle)
{
  double	y1;

  angle = (angle * M_PI) / 180;
  y1 = (1.3 * ((WIN_X / 2) - i)) / WIN_X;
  vec->x = 0.625 * cos(angle) - y1 * sin(angle);
  vec->y = 0.625 * sin(angle) + y1 * cos(angle);
}

void		check_wall(t_main_menu *data)
{
  int		i;
  t_vector	vec;

  i = -1;
  while (++i < WIN_X)
    {
      get_vector_pos(&vec, i, data->player.angle);
      get_wall_pos(&vec, data, i);
    }
}
