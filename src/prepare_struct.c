/*
** prepare_struct.c for gfx_wolf3d in /gfx_wolf3d/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 20 05:04:55 2015 Antoine Baché
** Last update Sun Dec 20 05:08:55 2015 Antoine Baché
*/

#include "my.h"

t_main_menu	*prepare_main()
{
  t_main_menu	*data;

  if ((data = bunny_malloc(sizeof(t_main_menu))) == NULL)
    return (NULL);
  data->select = 1;
  data->toggle_pause = 0;
  data->options.select = 1;
  data->options.music = 1;
  prepare_infos(&data->infos);
  return (data);
}
