/*
** pause_menu_draw.c for gfx_wolf3d in /gfx_wolf3d/src/menu
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Dec 15 00:52:07 2015 Antoine Baché
** Last update Tue Dec 22 02:50:00 2015 Antoine Baché
*/

#include "my.h"

void	sub_pause_titles(t_main_menu *menu)
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

void		put_pause_selector(t_main_menu *menu)
{
  if (menu->options.select == 1)
    display_bmp(menu, 4, 15, 175);
  else if (menu->options.select == 2)
    display_bmp(menu, 4, 15, 325);
}

void	fill_black_alpha(t_main_menu *menu)
{
  t_color	*color;
  int		i;

  i = -1;
  color = menu->pix->pixels;
  while (++i < WIN_X * WIN_Y)
    {
      color[i].full = color[i].full & 0x2B2B35;
    }
}

void	draw_pause_menu(t_main_menu *menu)
{
  fill_black_alpha(menu);
  sub_pause_titles(menu);
  put_pause_selector(menu);
  pause_menu_texture_disp(menu);
}
