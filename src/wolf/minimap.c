/*
** minimap.c for gfx_wolf3d in /gfx_wolf3d/src/wolf
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Dec 14 23:50:10 2015 Antoine Baché
** Last update Sat Dec 19 05:16:40 2015 Antoine Baché
*/

#include "my.h"
#include <stdio.h>

void		my_square(t_main_menu *data, unsigned int color, int i, int j)
{
  t_color	*colors;
  int		max_y;
  int		max_x;
  int		tmp;

  if (((data->map_size.height + i + 1) / data->map_size.tile) ==
      (int)data->player.posy && (j / data->map_size.tile) ==
      (int)data->player.posx)
    color = 0x3A4567;
  j += MAP_X_OFFSET;
  i += MAP_Y_OFFSET;
  max_y = i + SQUARE_SIZE;
  max_x = j + SQUARE_SIZE;
  tmp = j - 1;
  colors = data->pix->pixels;
  while (i < max_y)
    {
      j = tmp;
      while (++j < max_x)
	colors[i * WIN_X + j].full = color;
      i++;
    }
}

void		display_minimap(t_main_menu *data)
{
  int		i;
  int		j;

  i = 0;
  while (i <  data->map_size.height * data->map_size.tile)
    {
      j = 0;
      while (j < data->map_size.width * data->map_size.tile)
	{
	  if (data->map[i / data->map_size.tile][j / data->map_size.tile] == 0)
	    my_square(data, WHITE, i, j);
	  else
	    my_square(data, BLACK, i, j);
	  j += data->map_size.tile;
	}
      i += data->map_size.tile;
    }
}
