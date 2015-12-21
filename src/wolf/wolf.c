/*
** wolf.c for gfx_wolf3d in /gfx_wolf3d/src/wolf
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Dec 14 18:41:45 2015 Antoine Baché
** Last update Mon Dec 21 08:41:16 2015 Antoine Baché
*/

#include "my.h"

t_bunny_response	key_wolf(t_bunny_event_state state,
			    t_bunny_keysym key,
			     t_main_menu *data)
{
  if (key == BKS_ESCAPE && state == GO_DOWN && pause_menu(data) == 2)
    return (EXIT_ON_SUCCESS);
  else if ((key == BKS_UP || key == BKS_DOWN) && state == GO_DOWN)
    move_player(key, data);
  else if (state == GO_DOWN && (key == BKS_RIGHT || key == BKS_LEFT))
    rotate_player(key, data);
  return (GO_ON);
}

t_bunny_response	wolfloop(t_main_menu *menu)
{
  t_bunny_position	pos;

  if (menu->game_mode != 0)
    calc_pos_player(menu);
  pos.x = 0;
  pos.y = 0;
  display_wolf(menu);
  display_minimap(menu);
  bunny_blit(&(menu->win->buffer),
	     &(menu->pix->clipable), &pos);
  bunny_display(menu->win);
  return (GO_ON);
}

int	wolf(t_main_menu *menu)
{
  if (menu->game_mode == 0 && load_ini(menu) == 1)
    return (1);
  bunny_sound_stop(menu->music);
  bunny_delete_sound(menu->music);
  if ((menu->music = bunny_load_music("music/game.ogg")) == NULL)
    return (1);
  bunny_sound_volume(menu->music, 20 * menu->options.music);
  bunny_sound_play(menu->music);
  bunny_set_loop_main_function((t_bunny_loop)wolfloop);
  bunny_set_key_response((t_bunny_key)key_wolf);
  printf("/*\n** Wolf\n*/\n");
  bunny_loop(menu->win, 60, menu);
  bunny_sound_stop(menu->music);
  bunny_delete_sound(menu->music);
  if ((menu->music = bunny_load_music("music/main.ogg")) == NULL)
    return (1);
  bunny_sound_volume(menu->music, 20 * menu->options.music);
  bunny_sound_play(menu->music);
  bunny_set_loop_main_function((t_bunny_loop)mainMenuLoop);
  bunny_set_key_response((t_bunny_key)key);
  return (0);
}
