/*
** pos.c for gfx_wolf3d in /gfx_wolf3d/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 20 10:36:08 2015 Antoine Baché
** Last update Sun Dec 20 10:49:04 2015 Antoine Baché
*/

#include "my.h"

void	server_pos(t_main_menu *data);
{
  if ((socket_send(data->multi.serv_fd, data->player.posx) == -1))
    return ;
  data->player2.posx = socket_read(data->multi.serv_fd);
  if ((socket_send(data->multi.serv_fd, data->player.posy)) == -1)
    return ;
  data->player2.posy = socket_read(data->multi.serv_fd);
}

void	client_pos(t_main_menu *data)
{
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
}
