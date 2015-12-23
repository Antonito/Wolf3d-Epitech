/*
** my_getdouble.c for gfx_wolf3d in /gfx_wolf3d/src/wolf
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Dec 18 20:21:19 2015 Antoine Baché
** Last update Wed Dec 23 09:47:44 2015 Antoine Baché
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

void	remove_comma(char *str, char *tmp)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    tmp[i] = str[i];
  tmp[i] = '\0';
  i = -1;
  while (tmp[++i] != '.');
  while (tmp[i] != '\0')
    {
      tmp[i] = tmp[i + 1];
      i++;
    }
}

double		my_getdouble(char *str)
{
  int		i;
  int		k;
  double	res;
  char		*tmp;

  if (str == NULL)
    return (0);
  i = -1;
  k = 0;
  while (str[++i] != '.' && str[i] != '\0');
  if (str[i] == '\0')
    return (0);
  while (str[i] != '\0' && ++i && ++k);
  if ((tmp = bunny_malloc(my_strlen(str) + 1)) == NULL)
    return (1);
  remove_comma(str, tmp);
  k -= 1;
  res = ((k != 0) ? (double)my_getnbr(tmp) / my_power(10, k) : my_getnbr(tmp));
  bunny_free(tmp);
  return (res);
}
