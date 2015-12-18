/*
** minimap.c for gfx_wolf3d in /gfx_wolf3d/src/wolf
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Dec 14 23:50:10 2015 Antoine Baché
** Last update Fri Dec 18 18:08:14 2015 Antoine Baché
*/

#include "my.h"
#include <stdio.h>

void		my_square(t_main_menu *menu, unsigned int color, int i, int j)
{
  t_color	*colors;
  int		max_y;
  int		max_x;
  int		tmp;

  j += MAP_X_OFFSET;
  i += MAP_Y_OFFSET;
  max_y = i + SQUARE_SIZE;
  max_x = j + SQUARE_SIZE;
  tmp = j - 1;
  colors = menu->pix->pixels;
  while (i < max_y)
    {
      j = tmp;
      while (++j < max_x)
	colors[i * WIN_X + j].full = color;
      i++;
    }
}

void		display_minimap(t_main_menu *menu)
{
  int		i;
  int		j;

  i = 0;
  while (i <  menu->map_size.height * menu->map_size.tile)
    {
      j = 0;
      while (j < menu->map_size.width * menu->map_size.tile)
	{
	  if (menu->map[i / menu->map_size.tile][j / menu->map_size.tile] == 0)
	    my_square(menu, WHITE, i, j);
	  else
	    my_square(menu, BLACK, i, j);
	  j += menu->map_size.tile;
	}
      i += menu->map_size.tile;
    }
}
