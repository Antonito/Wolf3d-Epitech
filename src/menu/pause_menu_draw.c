/*
** pause_menu_draw.c for gfx_wolf3d in /gfx_wolf3d/src/menu
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Dec 15 00:52:07 2015 Antoine Baché
** Last update Mon Dec 21 10:15:15 2015 Antoine Baché
*/

#include "my.h"

void	pause_title(t_main_menu *menu)
{
  t_color	*color;
  int		i;

  i = -1;
  color = menu->pix->pixels;
  while (++i < WIN_X * MAIN_TITLE)
    color[i].full = WHITE;
}

void	sub_pause_titles(t_main_menu *menu)
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

void		put_pause_selector(t_main_menu *menu)
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
    color[min].full = BLUE;
}

void	fill_black_alpha(t_main_menu *menu)
{
  t_color	*color;
  int		i;

  i = -1;
  color = menu->pix->pixels;
  while (++i < WIN_X * WIN_Y)
    {
      color[i].full = BLACK;
    }
}

void	draw_pause_menu(t_main_menu *menu)
{
  fill_black_alpha(menu);
  pause_title(menu);
  sub_pause_titles(menu);
  put_pause_selector(menu);
}
