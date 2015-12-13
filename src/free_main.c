/*
** free_main.c for gfx_wolf3d in /gfx_wolf3d/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 13 01:54:54 2015 Antoine Baché
** Last update Sun Dec 13 01:57:35 2015 Antoine Baché
*/

#include "my.h"

int	free_on_winerror(t_main_menu *menu)
{
  bunny_free(menu);
  return (1);
}

int	free_on_pixerror(t_main_menu *menu)
{
  bunny_stop(menu->win);
  bunny_free(menu);
  return (1);
}
