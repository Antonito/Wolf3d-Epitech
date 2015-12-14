/*
** option_menu.c for gfx_wolf3d in /gfx_wolf3d/src/menu
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Dec 15 00:34:44 2015 Antoine Baché
** Last update Tue Dec 15 00:43:33 2015 Antoine Baché
*/

#include "my.h"

void	option_title(t_main_menu *menu)
{
  t_color	*color;
  int		i;

  i = -1;
  color = menu->pix->pixels;
  while (++i < WIN_X * MAIN_TITLE)
    color[i].full = WHITE;
}

void	sub_option_titles(t_main_menu *menu)
{
  t_color	*color;
  int		i;

  i = WIN_X * (MAIN_TITLE + SPACE_TITLE);
  color = menu->pix->pixels;
  while (++i < WIN_X * (MAIN_TITLE + SPACE_TITLE + SUB_TITLE))
    color[i].full = WHITE;
  i += SPACE_TITLE * WIN_X;
  while (++i < WIN_X * (MAIN_TITLE + (SPACE_TITLE + SUB_TITLE) * 2))
    color[i].full = WHITE;
}

void		put_option_selector(t_main_menu *menu)
{
  t_color	*color;
  int		min;
  int		max;

  color = menu->pix->pixels;
  if (menu->options.select == 1)
    {
      min = WIN_X * (MAIN_TITLE + SPACE_TITLE);
      max = WIN_X * (MAIN_TITLE + SPACE_TITLE + SUB_TITLE);
    }
  else if (menu->options.select == 2)
    {
      min = WIN_X * (MAIN_TITLE + SPACE_TITLE) * 2 - SPACE_TITLE * WIN_X;
      max = WIN_X * (MAIN_TITLE + (SPACE_TITLE + SUB_TITLE) * 2);
    }
  while (min++ < max)
    color[min].full = GREEN;
}

void	draw_option_menu(t_main_menu *menu)
{
  /*  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 10;*/
  fill_black(menu);
  option_title(menu);
  sub_option_titles(menu);
  put_option_selector(menu);
}
