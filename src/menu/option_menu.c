/*
** option_menu.c for gfx_wolf3d in /gfx_wolf3d/src/menu
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Dec 15 00:34:44 2015 Antoine Baché
** Last update Tue Dec 22 21:24:16 2015 Antoine Baché
*/

#include "my.h"

void	option_title(t_main_menu *menu)
{
  t_color	*color;
  int		i;

  i = -1;
  color = menu->pix->pixels;
  while (++i < WIN_X * MAIN_TITLE)
    color[i].full = BLACK;
}

void	sub_option_titles(t_main_menu *menu)
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
}

void		put_option_selector(t_main_menu *menu)
{
  if (menu->options.select == 1)
    display_bmp(menu, 4, 15, 175);
  else if (menu->options.select == 2)
    display_bmp(menu, 4, 15, 325);
}

void	draw_option_menu(t_main_menu *menu)
{
  fill_black(menu);
  option_title(menu);
  sub_option_titles(menu);
  option_menu_texture_disp(menu);
  put_option_selector(menu);
}
