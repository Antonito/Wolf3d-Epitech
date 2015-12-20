/*
** multiplayer.c for gfx_wolf3d in /gfx_wolf3d/src/multiplayer
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 20 05:30:04 2015 Antoine Baché
** Last update Sun Dec 20 19:24:14 2015 Antoine Baché
*/

#include "my.h"

int	client_map(t_main_menu *data)
{
  int	i;

  i = -1;
  if (client_map_basics(data) == 1)
    return (1);
  if ((data->map = bunny_malloc(sizeof(char *) *
				data->map_size.height)) == NULL)
    return (1);
  while (++i < data->map_size.height)
    {
      data->map[i] = socket_read(data->multi.client_fd);
      if ((socket_send(data->multi.client_fd, "OK")) == 1)
	return (1);
    }
  return (0);
}

int	start_client(t_main_menu *data)
{
  if ((data->multi.client_fd = client(data->infos.address,
				      data->infos.port)) == -1)
    return (1);
  if ((data->player2.pseudo = socket_read(data->multi.client_fd)) == NULL)
    return (1);
  if ((socket_send(data->multi.client_fd, data->infos.pseudo)) == 1)
    return (1);
  client_map(data);
  if (client_distant_player(data) == 1)
    return (1);
  data->player2.posx = my_getnbr(data->player2.pposx);
  printf("[STOCK] PosX P2 = %f PPOSX = %s\n", data->player2.posx, data->player2.pposx);
  data->player2.posy = my_getnbr(data->player2.pposy);
  printf("[STOCK] PosY P2 = %f PPOSY = %s\n", data->player2.posy, data->player2.pposy);
  data->player2.angle = my_getnbr(data->player2.pangle);
  printf("[STOCK] Angle P2 = %f Pangle = %s\n", data->player2.angle, data->player2.pangle);
  data->player.posx = 2;
  data->player.pposx = "2";
  data->player.posy = 1;
  data->player.pposy = "1";
  data->player.angle = 30;
  data->player.pangle = "30";
  return (0);
}

int	server_map(t_main_menu *data)
{
  int	i;

  i = -1;
  if ((socket_send(data->multi.serv_fd, data->multi.tile)) == 1)
    return (1);
  socket_read(data->multi.serv_fd);
  if ((socket_send(data->multi.serv_fd, data->multi.height)) == 1)
    return (1);
  socket_read(data->multi.serv_fd);
  if ((socket_send(data->multi.serv_fd, data->multi.width)) == 1)
    return (1);
  socket_read(data->multi.serv_fd);
  while (++i < data->map_size.height)
    {
      if ((socket_send_map(data->multi.serv_fd, data->map[i],
			   data->map_size.width)) == 1)
	return (1);
      socket_read(data->multi.serv_fd);
    }
  return (0);
}

int	start_server(t_main_menu *data)
{
  if ((data->multi.serv_fd = server(data->infos.port)) == -1)
    return (1);
  if ((socket_send(data->multi.serv_fd, data->infos.pseudo)) == 1)
    return (1);
  if ((data->player2.pseudo = socket_read(data->multi.serv_fd)) == NULL)
    return (1);
  if (load_ini_multi(data) == 1)
    return (1);
  if (server_map(data) == 1)
    return (1);
  if ((socket_send(data->multi.serv_fd, data->player.pposx)) == 1)
    return (1);
  socket_read(data->multi.serv_fd);
  if ((socket_send(data->multi.serv_fd, data->player.pposy)) == 1)
    return (1);
  socket_read(data->multi.serv_fd);
  if ((socket_send(data->multi.serv_fd, data->player.pangle)) == 1)
    return (1);
  socket_read(data->multi.serv_fd);
  return (0);
}

int	start_multiplayer(t_main_menu *data)
{
  if (data->game_mode == 2 && start_client(data) == 1)
    return (1);
  else if (data->game_mode == 3 && start_server(data) == 1)
    return (1);
  return (0);
}
