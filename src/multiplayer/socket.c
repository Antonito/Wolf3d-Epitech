/*
** socket.c for gfx_wolf3d in /gfx_wolf3d/src/multiplayer
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 20 02:32:00 2015 Antoine Baché
** Last update Tue Dec 22 15:45:20 2015 Antoine Baché
*/

#include "my.h"

double		socket_r_double(int fd)
{
  double	nb;

  if (recv(fd, &nb, sizeof(double), 0) == -1)
    return (0);
  return (nb);
}

char	*socket_read(int fd)
{
  char	*received;
  int	nb;

  if (fd == -1)
    return (NULL);
  if ((received = bunny_malloc(BUFF_SIZE + 1)) == NULL)
    return (NULL);
  if ((nb = read(fd, received, BUFF_SIZE)) == -1)
    return (NULL);
  received[nb] = '\0';
  return (received);
}

int	socket_send_double(int fd, double nb)
{
  if (write(fd, &nb, sizeof(double)) == -1)
    {
      write(2, "Error sending data\n", 19);
      return (1);
    }
  return (0);
}

int	socket_send_map(int fd, char *msg, int len)
{
  if (write(fd, msg, len) == -1)
    {
      write(2, "Error sending data\n", 19);
      return (1);
    }
  return (0);
}

int	socket_send(int fd, char *msg)
{
  if (write(fd, msg, my_strlen(msg)) == -1)
    {
      write(2, "Error sending data\n", 19);
      return (1);
    }
  return (0);
}
