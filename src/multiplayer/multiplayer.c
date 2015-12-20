/*
** multiplayer.c for gfx_wolf3d in /gfx_wolf3d/src/multiplayer
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 20 05:30:04 2015 Antoine Baché
** Last update Sun Dec 20 10:19:51 2015 Antoine Baché
*/

#include "my.h"

int	client_map(t_main_menu *data)
{
  int	i;
  char	*tmp;

  i = -1;
  tmp = socket_read(data->multi.client_fd);
  data->map_size.tile = my_getnbr(tmp);
  bunny_free(tmp);
  tmp = socket_read(data->multi.client_fd);
  data->map_size.height = my_getnbr(tmp);
  bunny_free(tmp);
  tmp = socket_read(data->multi.client_fd);
  data->map_size.width = my_getnbr(tmp);
  bunny_free(tmp);
  if ((data->map = bunny_malloc(sizeof(char *) *
				data->map_size.height)) == NULL)
    return (1);
  while (++i < data->map_size.height)
    data->map[i] = socket_read(data->multi.client_fd);
  return (0);
}

int	start_client(t_main_menu *data)
{
  char	*tmp;

  if ((data->multi.client_fd = client(data->infos.address,
				      data->infos.port)) == -1)
    return (1);
  if ((data->player2.pseudo = socket_read(data->multi.client_fd)) == NULL)
    return (1);
  if ((socket_send(data->multi.client_fd, data->infos.pseudo)) == 1)
    return (1);
  client_map(data);
  tmp = socket_read(data->multi.client_fd);
  data->player2.posx = my_getnbr(tmp);
  bunny_free(tmp);
  tmp = socket_read(data->multi.client_fd);
  data->player2.posy = my_getnbr(tmp);
  bunny_free(tmp);
  tmp = socket_read(data->multi.client_fd);
  data->player2.angle = my_getnbr(tmp);
  bunny_free(tmp);
  return (0);
}

int	server_map(t_main_menu *data)
{
  UNUSED int	i;

  i = -1;
  if ((socket_send(data->multi.serv_fd, data->multi.tile)) == 1)
    return (1);
  printf("[SEND] Tile = %s\n", data->multi.tile);
  printf("[READ] MSG = %s\n", socket_read(data->multi.serv_fd));
  if ((socket_send(data->multi.serv_fd, data->multi.height)) == 1)
    return (1);
  printf("[SEND] Height = %s\n", data->multi.height);
  printf("[READ] MSG = %s\n", socket_read(data->multi.serv_fd));
  if ((socket_send(data->multi.serv_fd, data->multi.width)) == 1)
    return (1);
  printf("[SEND] Width = %s\n", data->multi.width);
  printf("[READ] MSG = %s\n", socket_read(data->multi.serv_fd));
  while (++i < data->map_size.height)
    {
      if ((socket_send_map(data->multi.serv_fd, data->map[i],
			   data->map_size.width)) == 1)
	return (1);
      printf("[SEND] Map[%d] : %s\n", i, data->map[i]);
      printf("[READ] MSG = %s\n", socket_read(data->multi.serv_fd));
    }
  return (0);
}

int	start_server(t_main_menu *data)
{
  if ((data->multi.serv_fd = server(data->infos.port)) == -1)
    return (1);
  printf("Port = %d\n", data->infos.port);
  if ((socket_send(data->multi.serv_fd, data->infos.pseudo)) == 1)
    return (1);
  printf("[SEND] Pseudo = %s\n", data->infos.pseudo);
  if ((data->player2.pseudo = socket_read(data->multi.serv_fd)) == NULL)
    return (1);
  printf("[READ] Pseudo Distant = %s\n", data->player2.pseudo);
  if (load_ini_multi(data) == 1)
    return (1);
  if (server_map(data) == 1)
    return (1);
  if ((socket_send(data->multi.serv_fd, data->multi.pposx)) == 1)
    return (1);
  printf("[SEND] Player Posx = %s\n", data->multi.pposx);
  printf("[READ] MSG = %s\n", socket_read(data->multi.serv_fd));
  if ((socket_send(data->multi.serv_fd, data->multi.pposy)) == 1)
    return (1);
  printf("[SEND] Player Posy = %s\n", data->multi.pposy);
  printf("[READ] MSG = %s\n", socket_read(data->multi.serv_fd));
  if ((socket_send(data->multi.serv_fd, "33.3333")) == 1)
    return (1);
  printf("[SEND] Player Angle = %s\n", data->multi.pangle);
  printf("[READ] MSG = %s\n", socket_read(data->multi.serv_fd));
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
