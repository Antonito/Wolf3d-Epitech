/*
** my_strlen.c for gfx_wolf3d in /gfx_wolf3d/src/multiplayer
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 20 03:42:01 2015 Antoine Baché
** Last update Sun Dec 20 03:42:07 2015 Antoine Baché
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (*str)
    {
      str++;
      i++;
    }
  return (i);
}
