/*
** main.c for gfx_wolf3d in /gfx_wolf3d/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Dec 12 19:37:08 2015
** Last update Tue Dec 22 21:04:27 2015 Antoine Baché
*/

#include "my.h"

t_bunny_response	key_option(t_bunny_event_state state,
			    t_bunny_keysym key, t_main_menu *menu)
{
  if (key == BKS_UP && state == GO_DOWN && menu->options.select > 1)
    menu->options.select--;
  else if (key == BKS_DOWN && state == GO_DOWN && menu->options.select < 2)
    menu->options.select++;
  else if (key == BKS_RETURN && state == GO_DOWN &&
	   option_menu_actions(menu) == 1)
    return (EXIT_ON_SUCCESS);
  else if (key == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	OptionMenuLoop(t_main_menu *menu)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  draw_option_menu(menu);
  bunny_blit(&(menu->win->buffer),
	     &(menu->pix->clipable), &pos);
  bunny_display(menu->win);
  return (GO_ON);
}

int		option_menu(t_main_menu *menu)
{
  if (prepare_texture(menu) == 1 || option_menu_texture(menu) == 1)
    return (1);
  bunny_set_loop_main_function((t_bunny_loop)OptionMenuLoop);
  bunny_set_key_response((t_bunny_key)key_option);
  menu->select = 1;
  bunny_loop(menu->win, 60, menu);
  if (prepare_texture(menu) == 1 || main_menu_texture(menu) == 1)
    return (1);
  bunny_set_loop_main_function((t_bunny_loop)mainMenuLoop);
  bunny_set_key_response((t_bunny_key)key);
  return (0);
}
