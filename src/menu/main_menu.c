/*
** main_menu.c for gfx_wolf3d in /gfx_wolf3d/src/menu
**
** Made by
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 13 00:36:04 2015
** Last update Tue Dec 22 02:35:11 2015 Antoine Baché
*/

#include "my.h"

void	main_title(t_main_menu	*menu)
{
  t_color	*color;
  int		i;

  i = -1;
  color = menu->pix->pixels;
  while (++i < WIN_X * MAIN_TITLE)
    color[i].full = BLACK;
}

void	sub_titles(t_main_menu *menu)
{
  t_color	*color;
  int		i;

  i = WIN_X * (MAIN_TITLE + SPACE_TITLE);
  color = menu->pix->pixels;
  while (++i < WIN_X * (MAIN_TITLE + SPACE_TITLE + SUB_TITLE))
    color[i].full = BLACK;
  i += SPACE_TITLE * WIN_X;
  while (++i < WIN_X * (MAIN_TITLE + (SPACE_TITLE + SUB_TITLE) * 2))
    color[i].full = BLACK;
  i += SPACE_TITLE * WIN_X;
  while (++i < WIN_X * (MAIN_TITLE + (SPACE_TITLE + SUB_TITLE) * 3))
    color[i].full = BLACK;
}

void		put_selector(t_main_menu *menu)
{
  if (menu->select == 1)
    display_bmp(menu, 4, 15, 175);
  else if (menu->select == 2)
    display_bmp(menu, 4, 15, 325);
  else
    display_bmp(menu, 4, 15, 475);
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
  fill_black(menu);
  main_title(menu);
  sub_titles(menu);
  put_selector(menu);
}
