/*
** display_wall.c for gfx_wolf3d in /gfx_wolf3d/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Dec 22 00:24:43 2015 Antoine Baché
** Last update Wed Dec 23 00:08:49 2015 Antoine Baché
*/

#include "my.h"

int		game_texture(t_main_menu *menu)
{
  if (load_bmp(menu->texture[0], "img/wall.bmp") == 1 ||
      load_bmp(menu->texture[1], "img/gun.bmp") == 1 ||
      load_bmp(menu->texture[2], "img/wall.bmp") == 1 ||
      load_bmp(menu->texture[3], "img/wall.bmp") == 1 ||
      load_bmp(menu->texture[4], "img/wall.bmp") == 1)
    return (1);
  return (0);
}

void		display_texture_wall(t_main_menu *data, double k,
				     int i, t_vector *hit)
{
  int		demi_wall;
  int		start;
  int		end;
  t_color	*colors;
  int		j;

  demi_wall = WIN_Y / (2 * k);
  start = WIN_X * (WIN_Y / 2) + i - (WIN_X * demi_wall);
  end = WIN_X * (WIN_Y / 2) + i + (WIN_X * demi_wall);
  colors = data->pix->pixels;
  j = i;
  while (start < end && start >= 0 && end < WIN_X * WIN_Y)
    {
      colors[start].full =
	data->texture[0]->picture[(int)(WIN_Y * (hit->y - (int)hit->y)) % 64]
	[j % 64];
      start += WIN_X;
      j++;
    }
}
