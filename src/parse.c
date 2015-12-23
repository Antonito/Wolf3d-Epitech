/*
** parse.c for gfx_wolf3d in /gfx_wolf3d/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 20 04:36:38 2015 Antoine Baché
** Last update Wed Dec 23 21:51:31 2015 Antoine Baché
*/

#include "my.h"

void	prepare_infos(t_infos *infos)
{
  infos->pseudo = NULL;
  infos->address = NULL;
  infos->port = 0;
  infos->map = NULL;
}

void	parse_client(char **av, t_infos *infos)
{
  infos->pseudo = av[1];
  infos->address = av[3];
  infos->port = my_getnbr(av[4]);
}

void	parse_serv(char **av, t_infos *infos)
{
  infos->pseudo = av[1];
  infos->port = my_getnbr(av[3]);
  infos->map = av[4];
}

int	usage_message(void)
{
  write(2, "Usage solo: ./wolf3d map.ini\n", 29);
  write(2, "Usage client: ./wolf3d pseudo -c ip port\n", 41);
  write(2, "Usage server: ./wolf3d peusdo -h port map.ini [--pacman]\n", 46);
  return (1);
}

int	parse_args(int ac, char **av, t_infos *infos)
{
  infos->pacman = 0;
  if (ac == 2)
    infos->map = av[1];
  else if (my_strcmp(av[2], "-c") == 0 && ac == 5)
    {
      parse_client(av, infos);
      return (2);
    }
  else if ((my_strcmp(av[2], "-h") == 0 && ac >= 5) ||
	   (ac == 6 && my_strcmp(av[5], "--pacman") ==  0))
    {
      if (ac == 6)
	infos->pacman = 1;
      parse_serv(av, infos);
      return (3);
    }
  else
    return (usage_message());
  return (0);
}
