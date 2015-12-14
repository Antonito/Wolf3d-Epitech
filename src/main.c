/*
** main.c for gfx_wolf3d in /gfx_wolf3d/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Dec 12 19:37:08 2015
** Last update Mon Dec 14 21:14:06 2015 Antoine Baché
*/

#include "my.h"
#include <stdio.h>

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym key, t_main_menu *menu)
{
  if (key == BKS_UP && state == GO_DOWN && menu->select > 1)
    menu->select--;
  else if (key == BKS_DOWN && state == GO_DOWN && menu->select < 3)
    menu->select++;
  else if (key == BKS_RETURN && state == GO_DOWN &&
	   main_menu_actions(menu) == 1)
    return (EXIT_ON_SUCCESS);
  else if (key == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	mainMenuLoop(t_main_menu *menu)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  bunny_sound_volume(menu->music, 20 * menu->options.music);
  draw_menu(menu);
  bunny_blit(&(menu->win->buffer),
	     &(menu->pix->clipable), &pos);
  bunny_display(menu->win);
  return (GO_ON);
}

int		main_menu()
{
  t_main_menu	*menu;

  if ((menu = bunny_malloc(sizeof(t_main_menu))) == NULL)
    return (1);
  else if ((menu->win = bunny_start(WIN_X, WIN_Y, 0, "Wolf3D")) == NULL)
    return (ERROR_MAIN_WIN);
  else if ((menu->pix = bunny_new_pixelarray(WIN_X, WIN_Y)) == NULL)
    return (ERROR_MAIN_PIX);
  else if ((menu->music = bunny_load_music("music/main.ogg")) == NULL)
    return (ERROR_MAIN_MUSIC);
  bunny_set_loop_main_function((t_bunny_loop)mainMenuLoop);
  bunny_set_key_response((t_bunny_key)key);
  menu->select = 1;
  menu->options.select = 1;
  menu->options.music = 1;
  printf("/*\n** Main Menu\n*/\n");
  bunny_loop(menu->win, 60, menu);
  bunny_delete_sound(menu->music);
  bunny_stop(menu->win);
  bunny_delete_clipable(&menu->pix->clipable);
  bunny_free(menu);
  return (0);
}

int	main(UNUSED int ac, UNUSED char **av, char **env)
{
  if (*env == NULL || main_menu() == 1)
    return (1);
  return (0);
}
