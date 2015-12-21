/*
** load_bmp.c for gfx_wolf3d in /gfx_wolf3d/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Dec 14 01:07:09 2015 Antoine Baché
** Last update Mon Dec 21 15:42:16 2015 Antoine Baché
*/

#include "my.h"

void		display_bmp(t_texture *picture, t_main_menu *data)
{
  int		i;
  int		j;
  t_color	*colors;

  j = picture->height;
  colors = data->pix->pixels;
  while (--j >= 0)
    {
      i = -1;
      while (i++ < picture->width)
	colors[(picture->height - j) * WIN_X + i].full = picture->picture[j][i];
    }
}

int		load_bmp(t_texture *picture)
{
  t_bmp_header		header;
  t_bmp_info_header	info_header;
  int			fd;
  int			i;

  if ((fd = open("img/ExitPNG.bmp", O_RDONLY)) == -1)
    return (1);
  read(fd, &header, sizeof(t_bmp_header));
  read(fd, &info_header, sizeof(t_bmp_info_header));
  if (header.type !=0x4D42)
    {
      write(2, "Image is not a bmp\n", 19);
      return (1);
    }
  if ((picture->picture = bunny_malloc(sizeof(unsigned int *)
				       * ABS(info_header.height))) == NULL)
    return (1);
  i = -1;
  while (i < ABS(info_header.height))
    {
      if ((picture->picture[i] = bunny_malloc(sizeof(unsigned int)
				       * ABS(info_header.width))) == NULL)
    return (1);
      read(fd, picture->picture[i], ABS(info_header.width));
    }
  picture->width = ABS(info_header.width);
  picture->height = ABS(info_header.height);
  return (0);
}
