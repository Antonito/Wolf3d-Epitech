/*
** main_menu_texture.c for gfx_wolf3d in /gfx_wolf3d/src/texture
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Dec 21 20:43:53 2015 Antoine Baché
** Last update Mon Dec 21 22:07:34 2015 Antoine Baché
*/

#include "my.h"

int	main_menu_texture(t_main_menu *menu)
{
  if (load_bmp(menu->texture[0], "img/main_menu/ExitPNG.bmp") == 1 ||
      load_bmp(menu->texture[1], "img/main_menu/ExitPNG.bmp") == 1 ||
      load_bmp(menu->texture[2], "img/main_menu/ExitPNG.bmp") == 1 ||
      load_bmp(menu->texture[3], "img/main_menu/MainTitle.bmp") == 1)
    return (1);
  return (0);
}

void	main_menu_texture_disp(t_main_menu *data)
{
  display_bmp(data, 0, 120, 475);
  display_bmp(data, 1, 120, 325);
  display_bmp(data, 2, 120, 175);
  display_bmp(data, 3, 120, 0);
}