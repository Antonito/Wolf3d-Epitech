/*
** multi_client.c for gfx_wolf3d in /gfx_wolf3d/src/multiplayer
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 20 19:17:34 2015 Antoine Baché
** Last update Sun Dec 20 19:23:25 2015 Antoine Baché
*/

#include "my.h"

int	client_map_basics(t_main_menu *data)
{
  char	*tmp;

  tmp = socket_read(data->multi.client_fd);
  data->map_size.tile = my_getnbr(tmp);
  bunny_free(tmp);
  if ((socket_send(data->multi.client_fd, "OK")) == 1)
    return (1);
  tmp = socket_read(data->multi.client_fd);
  data->map_size.height = my_getnbr(tmp);
  bunny_free(tmp);
  if ((socket_send(data->multi.client_fd, "OK")) == 1)
    return (1);
  tmp = socket_read(data->multi.client_fd);
  data->map_size.width = my_getnbr(tmp);
  bunny_free(tmp);
  if ((socket_send(data->multi.client_fd, "OK")) == 1)
    return (1);
  return (0);
}

int	client_distant_player(t_main_menu *data)
{
  char	*tmp;

  tmp = socket_read(data->multi.client_fd);
  if ((data->player2.pposx = my_strdup(tmp)) == NULL)
    return (1);
  bunny_free(tmp);
  if ((socket_send(data->multi.client_fd, "OK")) == 1)
    return (1);
  tmp = socket_read(data->multi.client_fd);
  if ((data->player2.pposy = my_strdup(tmp)) == NULL)
    return (1);
  bunny_free(tmp);
  if ((socket_send(data->multi.client_fd, "OK")) == 1)
    return (1);
  tmp = socket_read(data->multi.client_fd);
  if ((data->player2.pangle = my_strdup(tmp)) == NULL)
    return (1);
  bunny_free(tmp);
  if ((socket_send(data->multi.client_fd, "OK")) == 1)
    return (1);
  return (0);
}
