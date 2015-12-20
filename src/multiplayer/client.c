/*
** client.c for gfx_wolf3d in /gfx_wolf3d/src/multiplayer
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 20 03:15:07 2015 Antoine Baché
** Last update Sun Dec 20 03:39:42 2015 Antoine Baché
*/

#include "my.h"

int			client(char *address, int port)
{
  int			fd;
  struct sockaddr_in	serv;

  if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      write(2, "Cannot create socket\n", 21);
      return (-1);
    }
  serv.sin_addr.s_addr = inet_addr(address);
  serv.sin_family = AF_INET;
  serv.sin_port = htons(port);
  if (connect(fd, (struct sockaddr *)&serv, sizeof(serv)) == -1)
    {
      write(2, "Cannot establish connection\n", 28);
      return (-1);
    }
  return (fd);
}
