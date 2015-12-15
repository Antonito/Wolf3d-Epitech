/*
** pause_menu.c for gfx_wolf3d in /gfx_wolf3d/src/menu
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Dec 14 21:34:34 2015 Antoine Baché
** Last update Tue Dec 15 01:14:57 2015 Antoine Baché
*/

#include "my.h"
#include <stdio.h>

t_bunny_response	key_pause(t_bunny_event_state state,
			    t_bunny_keysym key, t_main_menu *menu)
{
  if (key == BKS_UP && state == GO_DOWN && menu->options.select > 1)
    menu->options.select--;
  else if (key == BKS_DOWN && state == GO_DOWN && menu->options.select < 2)
    menu->options.select++;
  else if (key == BKS_RETURN && state == GO_DOWN)
    {
      if (pause_menu_actions(menu) == 1)
	return (EXIT_ON_SUCCESS);
      else
	// Modifier pointeur dans structure pour retour
    }
  else if (key == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	PauseMenuLoop(t_main_menu *menu)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  draw_pause_menu(menu);
  bunny_blit(&(menu->win->buffer),
	     &(menu->pix->clipable), &pos);
  bunny_display(menu->win);
  return (GO_ON);
}

int		pause_menu(t_main_menu *menu)
{
  bunny_set_loop_main_function((t_bunny_loop)PauseMenuLoop);
  bunny_set_key_response((t_bunny_key)key_pause);
  menu->select = 1;
  printf("/*\n** Pause Menu\n*/\n");
  bunny_loop(menu->win, 60, menu);
  bunny_set_loop_main_function((t_bunny_loop)wolfloop);
  bunny_set_key_response((t_bunny_key)key_wolf);
  return (0);
}
