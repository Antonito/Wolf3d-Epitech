/*
** main_menu.c for gfx_wolf3d in /gfx_wolf3d/src/menu
**
** Made by
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 13 00:36:04 2015
** Last update Sun Dec 13 01:38:03 2015 Antoine Baché
*/

#include "my.h"

void	main_title(t_main_menu	*menu)
{
  t_color	*color;
  int		i;

  i = -1;
  color = menu->pix->pixels;
  while (++i < WIN_X * MAIN_TITLE)
    color[i].full = WHITE;
}

void	sub_titles(t_main_menu *menu)
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
  i += SPACE_TITLE * WIN_X;
  while (++i < WIN_X * (MAIN_TITLE + (SPACE_TITLE + SUB_TITLE) * 3))
    color[i].full = WHITE;
}

void		put_selector(t_main_menu *menu)
{
  t_color	*color;
  int		min;
  int		max;

  color = menu->pix->pixels;
  if (menu->select == 1)
    {
      min = WIN_X * (MAIN_TITLE + SPACE_TITLE);
      max = WIN_X * (MAIN_TITLE + SPACE_TITLE + SUB_TITLE);
    }
  else if (menu->select == 2)
    {
      min = WIN_X * (MAIN_TITLE + SPACE_TITLE) * 2 - SPACE_TITLE * WIN_X;
      max = WIN_X * (MAIN_TITLE + (SPACE_TITLE + SUB_TITLE) * 2);
    }
  else
    {
      min = WIN_X * (MAIN_TITLE + SPACE_TITLE) * 3 - SPACE_TITLE * WIN_X * 2;
      max = WIN_X * (MAIN_TITLE + (SPACE_TITLE + SUB_TITLE) * 3);
    }
  while (min++ < max)
    color[min].full = RED;
}

void		fill_black(t_main_menu *menu)
{
  t_color	*color;
  int		i;

  i = -1;
  color = menu->pix->pixels;
  while (++i < WIN_X * WIN_Y)
    color[i].full = BLACK;
}

void			draw_menu(t_main_menu *menu)
{
  /*  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 10;*/
  fill_black(menu);
  main_title(menu);
  sub_titles(menu);
  put_selector(menu);
}
