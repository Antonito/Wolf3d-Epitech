/*
** opt_menu_texture.c for gfx_wolf3d in /gfx_wolf3d/src/texture
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Dec 21 21:21:59 2015 Antoine Baché
** Last update Tue Dec 22 19:18:20 2015 Antoine Baché
*/

#include "my.h"

int	option_menu_texture(t_main_menu *menu)
{
  if (load_bmp(menu->texture[0], "img/option_menu/MainMenu.bmp") == 1 ||
      load_bmp(menu->texture[1], "img/option_menu/MusicOff.bmp") == 1 ||
      load_bmp(menu->texture[2], "img/option_menu/MusicOn.bmp") == 1 ||
      load_bmp(menu->texture[3], "img/option_menu/OptionTitle.bmp") == 1 ||
      load_bmp(menu->texture[4], "img/cursor.bmp") == 1)
    return (1);
  return (0);
}

void	option_menu_texture_disp(t_main_menu *data)
{
  display_reversed_bmp(data, 0, 120, 325);
  display_bmp(data, 1 + data->options.music, 120, 175);
  display_bmp(data, 3, 120, 0);
}
