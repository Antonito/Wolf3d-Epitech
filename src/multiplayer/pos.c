/*
** pos.c for gfx_wolf3d in /gfx_wolf3d/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 20 10:36:08 2015 Antoine Baché
** Last update Sun Dec 20 20:54:27 2015 Antoine Baché
*/

#include "my.h"

void	set_player_pos(t_main_menu *data)
{
  if (((int)data->player2.oldposx != (int)data->player.posx) ||
      ((int)data->player2.oldposy != (int)data->player.posy))
  data->map[data->map_size.width - (int)data->player2.oldposx - 1]
    [data->map_size.height - (int)data->player2.oldposy - 1] = 0;
  data->map[data->map_size.width - (int)data->player2.posx - 1]
    [data->map_size.height - (int)data->player2.posy - 1] = 2;
}

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
  set_player_pos(data);
}
