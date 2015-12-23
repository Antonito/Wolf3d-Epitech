/*
** minimap.c for gfx_wolf3d in /gfx_wolf3d/src/wolf
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Dec 14 23:50:10 2015 Antoine Baché
** Last update Wed Dec 23 15:51:09 2015 Antoine Baché
*/

#include "my.h"

void		my_square(t_main_menu *data, unsigned int color, int i, int j)
{
  t_color	*colors;
  int		max_y;
  int		max_x;
  int		tmp;
  int		tile;

  tile = (data->map_size.width * data->map_size.height) / 5;
  if ((data->map_size.width - (i / tile) - 1) ==
      (int)data->player.posx &&
      (data->map_size.height - (j / tile) - 1) ==
      (int)data->player.posy)
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

void	display_minimap(UNUSED t_main_menu *data)
{
   return ;
}
