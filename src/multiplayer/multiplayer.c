/*
** multiplayer.c for gfx_wolf3d in /gfx_wolf3d/src/multiplayer
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 20 05:30:04 2015 Antoine Baché
** Last update Sun Dec 20 07:34:52 2015 Antoine Baché
*/

#include "my.h"

int	start_client(t_main_menu *data)
{
  if ((data->multi.client_fd = client(data->infos.address,
				      data->infos.port)) == -1)
    return (1);
  if ((data->player2.pseudo = socket_read(data->multi.client_fd)) == NULL)
    return (1);
  if ((socket_send(data->multi.client_fd, data->infos.pseudo)) == 1)
    return (1);
  return (0);
}

int	start_server(t_main_menu *data)
{
  int	i;

  i = -1;
  if ((data->multi.serv_fd = server(data->infos.port)) == -1)
    return (1);
  if ((socket_send(data->multi.serv_fd, data->infos.pseudo)) == 1)
    return (1);
  if ((data->player2.pseudo = socket_read(data->multi.serv_fd)) == NULL)
    return (1);
  if (load_ini_multi(data) == 1)
    return (1);
  if ((socket_send(data->multi.serv_fd, data->multi.tile)) == 1)
    return (1);
  if ((socket_send(data->multi.serv_fd, data->multi.height)) == 1)
    return (1);
  if ((socket_send(data->multi.serv_fd, data->multi.width)) == 1)
    return (1);
  while (++i < data->map_size.height)
    if ((socket_send(data->multi.serv_fd, data->map[i])) == 1)
      return (1);
  if ((socket_send(data->multi.serv_fd, data->multi.pposx)) == 1)
    return (1);
  if ((socket_send(data->multi.serv_fd, data->multi.pposy)) == 1)
    return (1);
  if ((socket_send(data->multi.serv_fd, data->multi.pangle)) == 1)
    return (1);
  return (0);
}

int	start_multiplayer(t_main_menu *data)
{
  load_ini_multi(data);
  if (data->game_mode == 2 && start_client(data) == 1)
    return (1);
  else if (data->game_mode == 3 && start_server(data) == 1)
    return (1);
  return (0);
}
