/*
** my_getdouble.c for gfx_wolf3d in /gfx_wolf3d/src/wolf
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Dec 18 20:21:19 2015 Antoine Baché
** Last update Fri Dec 18 21:19:03 2015 Antoine Baché
*/

#include "my.h"

int	my_power(int nb, int exp)
{
  int	i;

  i = 0;
  while (++i < exp)
    nb *= nb;
  return (nb);
}

void	remove_comma(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '.');
  while (str[i] != '\0')
    {
      str[i] = str[i + 1];
      i++;
    }
}

double		my_getdouble(char *str)
{
  int		i;
  int		k;
  double	res;

  if (str == NULL)
    return (0);
  i = -1;
  k = 0;
  while (str[++i] != '.' && str[i] != '\0');
  if (str[i] == '\0')
    return (0);
  while (str[i] != '\0' && ++i && ++k);
  remove_comma(str);
  k -= 1;
  res = ((k != 0) ? (double)my_getnbr(str) / my_power(10, k) : my_getnbr(str));
  return (res);
}
