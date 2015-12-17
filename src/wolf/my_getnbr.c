/*
** my_getnbr.c for colle-03 in /Piscine_C_colles-Semaine_03/lib/my/Test
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Oct 25 02:28:33 2015 Antoine Baché
** Last update Thu Dec 17 14:00:09 2015 Antoine Baché
*/

#include "my.h"

int	my_strlen_bis(char *str)
{
  int	i;

  i = 0;
  while (*str)
    {
      if (*str >= 48 && *str <= 57)
	++i;
      if (i > 0 && (*str < 48 || *str > 57))
	return (i);
      ++str;
    }
  return (i);
}

int	my_power_ten(int size)
{
  long	e;

  e = 1;
  while (size > 1)
    {
      e *= 10;
      --size;
    }
  return (e);
}

int	my_is_neg(char *str)
{
  int	is_neg;
  int	i;

  if (str == NULL)
    return (2);
  is_neg = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '-')
	++is_neg;
      ++i;
    }
  if (is_neg % 2 == 1)
    is_neg = 1;
  return (is_neg);
}

int		my_getnbr(char *str)
{
  int		size;
  double	total;
  int		pwr;
  int		is_neg;
  int		i;

  i = 0;
  if ((is_neg = my_is_neg(str)) == 2)
    return (0);
  size = my_strlen_bis(str);
  pwr = my_power_ten(size);
  total = 0;
  while (*str != '\0')
    {
      if (*str >= 48 && *str <= 57)
	{
	  total = total + ((*str - 48) * pwr);
	  pwr /= 10;
	  ++i;
	}
      ++str;
    }
  if (is_neg == 1)
      total = -total;
  return ((total > 2147483647 || total < -2147483648) ? 0 : total);
}
