/*
** display_wall.c for gfx_wolf3d in /gfx_wolf3d/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Dec 22 00:24:43 2015 Antoine Baché
** Last update Wed Dec 23 16:36:58 2015 Antoine Baché
*/

#include "my.h"

int		game_texture(t_main_menu *menu)
{
  if (load_bmp(menu->texture[0], "img/wall.bmp") == 1 ||
      load_bmp(menu->texture[1], "img/gun.bmp") == 1 ||
      load_bmp(menu->texture[2], "img/player.bmp") == 1 ||
      load_bmp(menu->texture[3], "img/wall.bmp") == 1 ||
      load_bmp(menu->texture[4], "img/wall.bmp") == 1)
    return (1);
  return (0);
}

void		display_texture_wall(t_main_menu *data, int demi_wall,
				     int i, t_vector *hit)
{
  int		start;
  int		end;
  t_color	*colors;
  int		j;
  t_vector	v;

  start = WIN_X * (WIN_Y / 2) + i - (WIN_X * demi_wall);
  end = WIN_X * (WIN_Y / 2) + i + (WIN_X * demi_wall);
  colors = data->pix->pixels;
  v.y = ABS((hit->y - (int)hit->y) - 0.5);
  v.x = ABS((hit->x - (int)hit->x) - 0.5);
  j = 0;
  while (start < end && start >= 0 && end < WIN_X * WIN_Y && ++j)
    {
      if (v.y >= v.x)
	colors[start].full =
	  data->texture[0]->picture[(int)(256 * (hit->x - (int)hit->x))]
	  [((256 * j) / (demi_wall * 2)) % 256];
      else
	colors[start].full =
	  data->texture[0]->picture[(int)(256 * (hit->y - (int)hit->y))]
	  [((256 * j) / (demi_wall * 2)) % 256];
      start += WIN_X;
    }
}

void		display_texture_player(t_main_menu *data, int demi_wall,
				     int i, t_vector *hit)
{
  int		start;
  int		end;
  t_color	*colors;
  int		j;
  t_vector	v;

  start = WIN_X * (WIN_Y / 2) + i - (WIN_X * demi_wall);
  end = WIN_X * (WIN_Y / 2) + i + (WIN_X * demi_wall);
  colors = data->pix->pixels;
  v.y = ABS((hit->y - (int)hit->y) - 0.5);
  v.x = ABS((hit->x - (int)hit->x) - 0.5);
  j = 0;
  while (start < end && start >= 0 && end < WIN_X * WIN_Y && ++j)
    {
      if (v.y >= v.x)
	colors[start].full =
	  data->texture[2]->picture[(int)(256 * (hit->x - (int)hit->x))]
	  [((256 * j) / (demi_wall * 2)) % 256];
      else
	colors[start].full =
	  data->texture[2]->picture[(int)(256 * (hit->y - (int)hit->y))]
	  [((256 * j) / (demi_wall * 2)) % 256];
      start += WIN_X;
    }
}
