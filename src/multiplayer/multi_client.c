/*
** multi_client.c for gfx_wolf3d in /gfx_wolf3d/src/multiplayer
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 20 19:17:34 2015 Antoine Baché
** Last update Sun Dec 20 21:11:47 2015 Antoine Baché
*/

#include "my.h"

int	serv_distant_player(t_main_menu *data)
{
  data->player2.posx = socket_r_double(data->multi.serv_fd);
  if ((socket_send(data->multi.serv_fd, "OK")) == 1)
    return (1);
  data->player2.posy = socket_r_double(data->multi.serv_fd);
  if ((socket_send(data->multi.serv_fd, "OK")) == 1)
    return (1);
  data->player2.angle = socket_r_double(data->multi.serv_fd);
  if ((socket_send(data->multi.serv_fd, "OK")) == 1)
    return (1);
  return (0);
}

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
  data->player2.posx = socket_r_double(data->multi.client_fd);
  if ((socket_send(data->multi.client_fd, "OK")) == 1)
    return (1);
  data->player2.posy = socket_r_double(data->multi.client_fd);
  if ((socket_send(data->multi.client_fd, "OK")) == 1)
    return (1);
  data->player2.angle = socket_r_double(data->multi.client_fd);
  if ((socket_send(data->multi.client_fd, "OK")) == 1)
    return (1);
  set_client_position(data);
  if ((socket_send_double(data->multi.client_fd, data->player.posx)) == 1)
    return (1);
  socket_read(data->multi.client_fd);
  if ((socket_send_double(data->multi.client_fd, data->player.posy)) == 1)
    return (1);
  socket_read(data->multi.client_fd);
  if ((socket_send_double(data->multi.client_fd, data->player.angle)) == 1)
    return (1);
  socket_read(data->multi.client_fd);
  return (0);
}

/*
** Faire un placement par analyse de la carte
*/
void	set_client_position(t_main_menu *data)
{
  data->player.posx = 1;
  data->player.posy = 2;
  data->player.angle = 35;
}
