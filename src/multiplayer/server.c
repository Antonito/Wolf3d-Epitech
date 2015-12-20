/*
** server.c for gfx_wolf3d in /gfx_wolf3d/src/multiplayer
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 20 02:31:07 2015 Antoine Baché
** Last update Sun Dec 20 03:59:16 2015 Antoine Baché
*/

#include "my.h"

int	bind_serv(struct sockaddr_in *serv, int fd, int port)
{
  serv->sin_addr.s_addr = INADDR_ANY;
  serv->sin_family = AF_INET;
  serv->sin_port = htons(port);
  if (bind(fd, (struct sockaddr *)serv, sizeof(*serv)) == -1)
    {
      write(2, "Cannot start server\n", 20);
      return (1);
    }
  return (0);
}

int			server(int port)
{
  int			fd;
  int			final;
  int			socket_size;
  struct sockaddr_in	serv;
  struct sockaddr_in	client;

  if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      write(2, "Cannot create socket\n", 21);
      return (-1);
    }
  if (bind_serv(&serv, fd, port) == 1)
    return (-1);
  listen(fd, 1);
  socket_size = sizeof(struct sockaddr_in);
  if ((final = accept(fd, (struct sockaddr *)&client,
		      (socklen_t *)&socket_size)) < 0)
    {
      write(2, "Cannot accept client\n", 21);
      return (-1);
    }
   return (final);
}
