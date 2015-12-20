/*
** my_strdup.c for gfx_wolf3d in /gfx_wolf3d/src/multiplayer
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 20 18:22:10 2015 Antoine Baché
** Last update Sun Dec 20 18:32:20 2015 Antoine Baché
*/

#include "my.h"

char	*my_strdup(char *str)
{
  char	*dest;
  int	i;
  int	len;

  len = my_strlen(str);
  if ((dest = malloc(len + 1)) == NULL)
    return (NULL);
  i = -1;
  while (++i < len)
    dest[i] = str[i];
  dest[i] = '\0';
  return (dest);
}
