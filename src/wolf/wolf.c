/*
** wolf.c for gfx_wolf3d in /gfx_wolf3d/src/wolf
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Dec 14 18:41:45 2015 Antoine Baché
** Last update Sat Dec 19 06:24:17 2015 Antoine Baché
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

void		set_to_black(t_main_menu *menu)
{
  int		i;
  t_color	*colors;

  i = -1;
  colors = menu->pix->pixels;
  while (++i < WIN_X * WIN_Y)
    colors[i].full = PINK;
}

t_bunny_response	wolfloop(t_main_menu *menu)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  set_to_black(menu);
  display_wolf(menu);
  display_minimap(menu);
  bunny_blit(&(menu->win->buffer),
	     &(menu->pix->clipable), &pos);
  bunny_display(menu->win);
  return (GO_ON);
}

int	wolf(t_main_menu *menu)
{
  bunny_sound_stop(menu->music);
  bunny_delete_sound(menu->music);
  load_ini(menu);
  if ((menu->music = bunny_load_music("music/game.ogg")) == NULL)
    return (1);
  bunny_sound_volume(menu->music, 100);
  bunny_sound_play(menu->music);
  bunny_set_loop_main_function((t_bunny_loop)wolfloop);
  bunny_set_key_response((t_bunny_key)key_wolf);
  printf("/*\n** Wolf\n*/\n");
  bunny_loop(menu->win, 60, menu);
  bunny_sound_stop(menu->music);
  bunny_delete_sound(menu->music);
  if ((menu->music = bunny_load_music("music/main.ogg")) == NULL)
    return (1);
  bunny_sound_play(menu->music);
  bunny_set_loop_main_function((t_bunny_loop)mainMenuLoop);
  bunny_set_key_response((t_bunny_key)key);
  return (0);
}
