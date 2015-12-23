/*
** main.c for gfx_wolf3d in /gfx_wolf3d/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Dec 12 19:37:08 2015
** Last update Wed Dec 23 21:42:31 2015 Antoine Baché
*/

#include "my.h"

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym key, t_main_menu *menu)
{
  if (key == BKS_UP && state == GO_DOWN && menu->select > 1)
    menu->select--;
  else if (key == BKS_DOWN && state == GO_DOWN && menu->select < 3)
    menu->select++;
  else if (key == BKS_RETURN && state == GO_DOWN &&
	   main_menu_actions(menu) == 1)
    return (EXIT_ON_ERROR);
  else if ((key == BKS_ESCAPE && state == GO_DOWN) ||
	   (menu->select == 3 && key == BKS_RETURN &&
	    state == GO_DOWN && main_menu_actions(menu) == 2))
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	mainMenuLoop(t_main_menu *menu)
{
  draw_menu(menu);
  main_menu_texture_disp(menu);
  bunny_blit(&(menu->win->buffer),
	     &(menu->pix->clipable), 0);
  bunny_display(menu->win);
  return (GO_ON);
}

int	main_menu(t_main_menu *menu)
{
  set_max_heap_size(20);
  if ((menu->win = bunny_start(WIN_X, WIN_Y, 0, "Wolf3D")) == NULL)
    return (ERROR_MAIN_WIN);
  else if ((menu->pix = bunny_new_pixelarray(WIN_X, WIN_Y)) == NULL)
    return (ERROR_MAIN_PIX);
  else if ((menu->music = bunny_load_music("music/main.ogg")) == NULL)
    return (ERROR_MAIN_MUSIC);
  else if (prepare_texture(menu) == 1 || main_menu_texture(menu) == 1)
    return (1);
  bunny_set_loop_main_function((t_bunny_loop)mainMenuLoop);
  bunny_set_key_response((t_bunny_key)key);
  bunny_sound_volume(menu->music, 20 * menu->options.music);
  bunny_sound_play(menu->music);
  bunny_loop(menu->win, 60, menu);
  bunny_delete_sound(menu->music);
  bunny_stop(menu->win);
  bunny_delete_clipable(&menu->pix->clipable);
  bunny_free(menu);
  return (0);
}

int		start_game(int ac, char **av)
{
  t_main_menu	*data;

  if ((data = prepare_main()) == NULL)
    return (1);
  if (ac >= 2 && (data->game_mode = parse_args(ac, av, &data->infos)) == 1)
    return (1);
  if (data->game_mode != 0 && start_multiplayer(data) == 1)
    return (1);
  if (main_menu(data) == 1)
    return (1);
  return (0);
}

int		main(int ac, char **av, char **env)
{
  if (*env == NULL || env == NULL)
    return (1);
  if (ac > 6 || ac < 2)
    return (usage_message());
  if (start_game(ac, av) == 1)
    return (1);
  return (0);
}
