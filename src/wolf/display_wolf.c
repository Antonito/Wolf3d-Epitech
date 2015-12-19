/*
** display_wolf.c for gfx_wolf3d in /gfx_wolf3d/src/wolf
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Dec 18 18:15:07 2015 Antoine Baché
** Last update Sat Dec 19 02:22:11 2015 Antoine Baché
*/

#include "my.h"

void		set_sky(t_main_menu *menu)
{
  int		i;
  t_color	*colors;

  i = -1;
  colors = menu->pix->pixels;
  while (++i < (WIN_X * WIN_Y) / 2)
    colors[i].full = SKY_COLOR;
}

void		set_ground(t_main_menu *menu)
{
  int		i;
  t_color	*colors;

  i = (WIN_X * WIN_Y) / 2 - 1;
  colors = menu->pix->pixels;
  while (++i < WIN_X * WIN_Y)
    colors[i].full = GROUND_COLOR;
}

void	display_wolf(t_main_menu *menu)
{
  set_sky(menu);
  set_ground(menu);
  check_wall(menu);
}
