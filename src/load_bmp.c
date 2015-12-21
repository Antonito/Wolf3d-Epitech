/*
** load_bmp.c for gfx_wolf3d in /gfx_wolf3d/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Dec 14 01:07:09 2015 Antoine Baché
** Last update Mon Dec 21 11:56:22 2015 Antoine Baché
*/

#include "my.h"

void		display_bmp(t_texture *picture, t_main_menu *data)
{
  int		i;
  int		j;
  int		tmp;
  t_color	*colors;

  i = -1;
  j = -1;
  tmp = -1;
  colors = data->pix->pixels;
  while (++i < picture->height * picture->width)
    {
      colors[++j].full = picture->picture[i];
      if (++tmp == picture->width)
	{
	  j += WIN_X - picture->width;
	  tmp = 0;
	}
    }
}

int		load_bmp(t_texture *picture)
{
  t_bmp_header		header;
  t_bmp_info_header	info_header;
  int			fd;
  int			readed;

  if ((fd = open("img/ExitPNG.bmp", O_RDONLY)) == -1)
    return (1);
  readed = read(fd, &header, sizeof(t_bmp_header));
  read(fd, &info_header, sizeof(t_bmp_info_header));
  if (header.type !=0x4D42)
    {
      write(2, "Image is not a bmp\n", 19);
      return (1);
    }
  if ((picture->picture = bunny_malloc(sizeof(unsigned int) *
				 ABS(info_header.width) *
				 ABS(info_header.height))) == NULL)
    return (1);
  readed = read(fd, picture->picture,
		ABS(info_header.width) * ABS(info_header.height));
  if (readed != ABS(info_header.width) * ABS(info_header.height))
    return (1);
  picture->width = ABS(info_header.width);
  picture->height = ABS(info_header.height);
  return (0);
}
