/*
** minimap.c for gfx_wolf3d in /gfx_wolf3d/src/wolf
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Dec 14 23:50:10 2015 Antoine Baché
** Last update Tue Dec 15 00:14:55 2015 Antoine Baché
*/

#include "my.h"

void		display_minimap(t_main_menu *menu)
{
  int		i;
  int		j;
  t_color	*colors;

  j = 480 * WIN_X + 19;
  colors = menu->pix->pixels;
  while (j < WIN_X * 580 + 69)
    {
      i = -1;
      while (i++ < 100)
	colors[i + j].full = WHITE;
      j += WIN_X;
    }
}
