/*
** load_bmp.c for gfx_wolf3d in /gfx_wolf3d/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Dec 14 01:07:09 2015 Antoine Baché
** Last update Mon Dec 14 17:54:00 2015 Antoine Baché
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define BUFF_SIZE 345678

unsigned long	*load_bmp()
{
  unsigned long	*buff;
  int		fd;
  int		i;

  i = 0;
  if ((buff = malloc(sizeof(unsigned long) * BUFF_SIZE)) == NULL)
    return (NULL);
  else if ((fd = open("img/ExitPNG.bmp", O_RDONLY)) == -1)
    return (NULL);
  read(fd, buff, BUFF_SIZE - 1);
  while (++i < BUFF_SIZE)
    printf("buff[i] = %ld\n", buff[i]);
  return (buff);
}
