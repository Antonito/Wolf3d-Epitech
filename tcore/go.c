/*
** go.c for gfx_wolf3d in /gfx_wolf3d/tcore
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 13 10:39:21 2015 Antoine Baché
** Last update Mon Dec 21 17:20:57 2015 Antoine Baché
*/

#include <lapin.h>

void	go(t_bunny_position *curpos, double angle,
	   t_bunny_position *newpos, int move)
{
  newpos->x = curpos->x + move * (int)(cos(angle * M_PI) / 180);
  newpos->y = curpos->y + move * (int)(sin(angle * M_PI) / 180);
}
