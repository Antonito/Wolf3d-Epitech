/*
** option_menu_actions.c for gfx_wolf3d in /gfx_wolf3d/src/menu
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 13 13:10:28 2015 Antoine Baché
** Last update Tue Dec 22 01:58:36 2015 Antoine Baché
*/

#include "my.h"

int	option_menu_actions(t_main_menu *data)
{
  if (data->options.select == 1)
    {
      display_reversed_bmp(data, 2, 120, 175);
      data->options.music = ((data->options.music == 1) ? 0 : 1);
      bunny_sound_volume(data->music, 20 * data->options.music);
    }
  else if (data->options.select == 2)
    return (1);
  return (0);
}
