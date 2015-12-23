/*
** prepare_texture.c for gfx_wolf3d in /gfx_wolf3d/src/texture
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Dec 22 03:27:23 2015 Antoine Baché
** Last update Wed Dec 23 09:40:03 2015 Antoine Baché
*/

#include "my.h"

void	free_texture(t_texture *pic)
{
  int	j;

  j = -1;
  while (++j < pic->height)
    if (pic->picture[j] != NULL)
      bunny_free(pic->picture[j]);
  if (pic->picture != NULL)
    bunny_free(pic->picture);
}

int	prepare_texture(t_main_menu *data)
{
  int	i;

  i = -1;
  if (data->texture != NULL)
    {
      while (++i < 5)
	{
	  free_texture(data->texture[i]);
	  bunny_free(data->texture[i]);
	}
      bunny_free(data->texture);
    }
  if ((data->texture = bunny_malloc(sizeof(t_texture *) * 5)) == NULL)
    return (1);
  i = -1;
  while (++i < 5)
    if ((data->texture[i] = bunny_malloc(sizeof(t_texture))) == NULL)
      return (1);
  return (0);
}
