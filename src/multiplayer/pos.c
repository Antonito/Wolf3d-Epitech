/*
** pos.c for gfx_wolf3d in /gfx_wolf3d/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 20 10:36:08 2015 Antoine Baché
** Last update Sun Dec 20 20:38:37 2015 Antoine Baché
*/

#include "my.h"

void	server_pos(t_main_menu *data)
{
  if ((socket_send_double(data->multi.serv_fd, data->player.posx) == -1))
    return ;
  data->player2.posx = socket_r_double(data->multi.serv_fd);
  if ((socket_send_double(data->multi.serv_fd, data->player.posy)) == -1)
    return ;
  data->player2.posy = socket_r_double(data->multi.serv_fd);
  if ((socket_send_double(data->multi.serv_fd, data->player.angle)) == -1)
    return ;
  data->player2.angle = socket_r_double(data->multi.serv_fd);
}

void	client_pos(t_main_menu *data)
{
  data->player2.posx = socket_r_double(data->multi.client_fd);
  if ((socket_send_double(data->multi.client_fd, data->player.posx) == -1))
    return ;
  data->player2.posy = socket_r_double(data->multi.client_fd);
  if ((socket_send_double(data->multi.client_fd, data->player.posy)) == -1)
    return ;
  data->player2.angle = socket_r_double(data->multi.client_fd);
  if ((socket_send_double(data->multi.client_fd, data->player.angle)) == -1)
    return ;
}

void	calc_pos_player(t_main_menu *data)
{
  data->player2.oldposx = data->player2.posx;
  data->player2.oldposy = data->player2.posy;
  if (data->game_mode == 2)
    client_pos(data);
  else
    server_pos(data);
  printf("Local P: x = %f y = %f a = %f\n", data->player.posx, data->player.posy, data->player.angle);
  printf("Distant P: x = %f y = %f a = %f\n", data->player2.posx, data->player2.posy, data->player2.angle);
}
