/*
** vecnorm.c for gfx_wolf3d in /gfx_wolf3d/tcore
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 13 10:35:00 2015 Antoine Baché
** Last update Sun Dec 13 10:38:22 2015 Antoine Baché
*/

#include <lapin.h>
#include <math.h>

double		vercnorm(t_bunny_position *coord0, t_bunny_position *coord1)
{
  double	norme;

  norme = sqrt(((coord1->x - coord0->x) * (coord1->x - coord0->x)) +
	       ((coord1->y - coord0->y) * (coord1->y - coord0->y)));
  return (norme);
}
