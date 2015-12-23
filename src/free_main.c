/*
** free_main.c for gfx_wolf3d in /gfx_wolf3d/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 13 01:54:54 2015 Antoine Baché
** Last update Wed Dec 23 09:22:28 2015 Antoine Baché
*/

#include "my.h"

int	free_on_winerror(t_main_menu *data)
{
  bunny_free(data);
  return (1);
}

int	free_on_pixerror(t_main_menu *data)
{
  bunny_stop(data->win);
  bunny_free(data);
  return (1);
}

int	free_on_musicerror(t_main_menu *data)
{
  bunny_stop(data->win);
  bunny_delete_clipable(&data->pix->clipable);
  bunny_free(data);
  return (1);
}
