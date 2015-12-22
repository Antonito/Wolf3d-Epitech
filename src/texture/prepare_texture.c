/*
** prepare_texture.c for gfx_wolf3d in /gfx_wolf3d/src/texture
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Dec 22 03:27:23 2015 Antoine Baché
** Last update Tue Dec 22 03:41:08 2015 Antoine Baché
*/

#include "my.h"

int	prepare_texture(t_main_menu *data)
{
  int	i;

  i = -1;
  if (data->texture != NULL)
    while (++i < 5)
      bunny_free(data->texture[i]);
  if ((data->texture = bunny_malloc(sizeof(t_texture *) * 5)) == NULL)
    return (1);
  i = -1;
  while (++i < 5)
    if ((data->texture[i] = bunny_malloc(sizeof(t_texture))) == NULL)
      return (1);
  return (0);
}
