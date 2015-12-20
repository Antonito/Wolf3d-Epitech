/*
** my_strcmp.c for fdf1 in /gfx_fdf1/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Nov 18 20:56:26 2015 Antoine Baché
** Last update Sun Dec 20 05:16:47 2015 Antoine Baché
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	j;
  int	t;

  i = 0;
  j = 0;
  t = my_strlen(s1);
  i = 0;
  if (t < my_strlen(s2))
    t = my_strlen(s2);
  while (i < t + 1 && j == 0)
    {
      if (s1[i] != s2[i])
	j = s1[i] - s2[i];
      i = i + 1;
    }
  return (j);
}
