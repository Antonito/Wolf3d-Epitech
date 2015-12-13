/*
** main.c for gfx_wolf3d in /gfx_wolf3d/src
**
** Made by
** Login   <bache_a@epitech.net>
**
** Started on  Sat Dec 12 19:37:08 2015
** Last update Sat Dec 12 19:37:17 2015 
*/

#include "my.h"

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym key,
			    void *prog)
{
  if (state == GO_DOWN && key != BKS_ESCAPE)
    go_down_key(key, prog);
  else if (state == GO_UP && key != BKS_ESCAPE)
    go_up_key(key, prog);
  else if (key == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	mainloop(t_prog *prog)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  if (prog->mod[0] && prog->mod[3] < 19)
    prog->mod[3] += 1;
  else if (prog->mod[1] && prog->mod[3] > 0)
    prog->mod[3] -= 1;
  bunny_sound_volume(prog->music, prog->mod[3] * 4 + 20);
  random_lines(prog->colors);
  fire_calculator(prog->colors, prog->mod[3]);
  display_fire(prog->pix, prog->colors, prog->palette);
  bunny_blit(&(prog->win->buffer),
	     &(prog->pix->clipable), &pos);
  bunny_display(prog->win);
  return (GO_ON);
}

void	set_to_black(short *colors)
{
  int	i;

  i = -1;
  while (++i < WIN_X * (WIN_Y + 2))
    colors[i] = 0;
}

int		flame()
{
  t_prog	*prog;

  if ((prog = bunny_malloc(sizeof(t_prog))) == NULL)
    return (-1);
  palette_generator(prog->palette);
  srand(time(NULL));
  prog->mod[0] = 0;
  prog->mod[1] = 0;
  prog->mod[3] = 14;
  prog->win = bunny_start(WIN_X, WIN_Y, 0, "Flame");
  set_to_black(prog->colors);
  prog->pix = bunny_new_pixelarray(WIN_X, WIN_Y);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response(key);
  if ((prog->music = bunny_load_music("sounds/fire.ogg")) == NULL)
    return (-1);
  load_music(prog->music);
  bunny_loop(prog->win, 60, prog);
  bunny_delete_sound(prog->music);
  bunny_stop(prog->win);
  bunny_delete_clipable(&prog->pix->clipable);
  bunny_free(prog);
  return (0);
}

int	main(UNUSED int ac, UNUSED char **av, char **env)
{
  if (*env == NULL || flame() == -1)
    return (-1);
  return (0);
}
