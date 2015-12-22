/*
** load_bmp.c for gfx_wolf3d in /gfx_wolf3d/src/texture
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Dec 14 01:07:09 2015 Antoine Baché
** Last update Tue Dec 22 21:08:26 2015 Antoine Baché
*/

#include "my.h"

void		display_reversed_bmp(t_main_menu *data,
			      int index, int off_x, int off_y)
{
  int		i;
  int		j;
  int		tmp;
  t_color	*colors;

  j = data->texture[index]->height;
  tmp = off_y;
  colors = data->pix->pixels;
  while (--j >= 0)
    {
      i = -1;
      while (++i < data->texture[index]->width)
	{
	  colors[tmp * WIN_X + i + off_x].full =
	    data->texture[index]->picture[j][i];
	}
      tmp++;
    }
}

void		display_bmp(t_main_menu *data, int index, int off_x, int off_y)
{
  int		i;
  int		j;
  int		tmp;
  t_color	*colors;

  j = -1;
  tmp = off_y;
  colors = data->pix->pixels;
  while (++j < data->texture[index]->height)
    {
      i = -1;
      while (++i < data->texture[index]->width)
	{
	  colors[tmp * WIN_X + i + off_x].full =
	    data->texture[index]->picture[j][i];
	}
      tmp++;
    }
}

int	bmp_error(void)
{
  write(2, "Image is not a bmp\n", 19);
  return (1);
}

int		load_bmp(t_texture *picture, char *file)
{
  int			fd;
  int			i;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (1);
  read(fd, &picture->head, sizeof(t_bmp_header));
  read(fd, &picture->info, sizeof(t_bmp_info_header));
  if (picture->head.type !=0x4D42)
    return (bmp_error());
  if ((picture->picture = malloc(sizeof(unsigned int *)
				       * ABS(picture->info.height))) == NULL)
    return (1);
  i = -1;
  while (++i < ABS(picture->info.height))
    {
      if ((picture->picture[i] = malloc(sizeof(unsigned int)
				       * ABS(picture->info.width))) == NULL)
	return (1);
      read(fd, picture->picture[i], ABS(picture->info.width) * 4);
    }
  picture->width = ABS(picture->info.width);
  picture->height = ABS(picture->info.height);
  return ((close(fd) == 1) ? 1 : 0);
}
