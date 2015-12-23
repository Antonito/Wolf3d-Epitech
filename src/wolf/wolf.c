/*
** wolf.c for gfx_wolf3d in /gfx_wolf3d/src/wolf
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Dec 14 18:41:45 2015 Antoine Baché
** Last update Wed Dec 23 09:39:28 2015 Antoine Baché
*/

#include "my.h"

t_bunny_response	key_wolf(t_bunny_event_state state,
				 UNUSED t_bunny_keysym key,
				 t_main_menu *data)
{
  const bool   		*keys;
  int			save;

  if (state == GO_DOWN)
    {
      keys = bunny_get_keyboard();
      if (keys[BKS_ESCAPE])
	{
	  if ((save = pause_menu(data)) == 2)
	    return (EXIT_ON_SUCCESS);
	  else if (save == 1)
	    return (EXIT_ON_ERROR);
	}
      if (keys[BKS_UP] || keys[BKS_DOWN])
	move_player(((keys[BKS_UP]) ? BKS_UP : BKS_DOWN), data);
      if (keys[BKS_RIGHT] || keys[BKS_LEFT])
	rotate_player(((keys[BKS_RIGHT]) ? BKS_RIGHT : BKS_LEFT), data);
    }
  return (GO_ON);
}

t_bunny_response	wolfloop(t_main_menu *data)
{
  if (data->game_mode != 0)
    calc_pos_player(data);
  display_wolf(data);
  display_minimap(data);
  bunny_blit(&(data->win->buffer),
	     &(data->pix->clipable), 0);
  bunny_display(data->win);
  return (GO_ON);
}

int	wolf(t_main_menu *data)
{
  if (data->game_mode == 0 && load_ini(data) == 1)
    return (1);
  bunny_sound_stop(data->music);
  bunny_delete_sound(data->music);
  if ((data->music = bunny_load_music("music/game.ogg")) == NULL)
    return (1);
  if (prepare_texture(data) == 1 || game_texture(data) == 1)
    return (1);
  bunny_sound_volume(data->music, 20 * data->options.music);
  bunny_sound_play(data->music);
  bunny_set_loop_main_function((t_bunny_loop)wolfloop);
  bunny_set_key_response((t_bunny_key)key_wolf);
  bunny_loop(data->win, 60, data);
  bunny_sound_stop(data->music);
  bunny_delete_sound(data->music);
  if ((data->music = bunny_load_music("music/main.ogg")) == NULL)
    return (1);
  bunny_sound_volume(data->music, 20 * data->options.music);
  bunny_sound_play(data->music);
  if (prepare_texture(data) == 1 || main_menu_texture(data) == 1)
    return (1);
  bunny_set_loop_main_function((t_bunny_loop)mainMenuLoop);
  bunny_set_key_response((t_bunny_key)key);
  return (0);
}
