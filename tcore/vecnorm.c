/*
** vecnorm.c for gfx_wolf3d in /gfx_wolf3d/tcore
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 13 10:35:00 2015 Antoine Baché
** Last update Wed Mar  2 20:27:02 2016 Antoine Baché
*/

#include <lapin.h>
#include <math.h>

double		vecnorm(t_bunny_position *coord0, t_bunny_position *coord1)
{
  double	norme;

  norme = sqrt(((coord1->x - coord0->x) * (coord1->x - coord0->x)) +
	       ((coord1->y - coord0->y) * (coord1->y - coord0->y)));
  return (norme);
}
