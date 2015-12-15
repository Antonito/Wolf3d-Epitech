/*
** pause_menu_actions.c for gfx_wolf3d in /gfx_wolf3d/src/menu
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Dec 15 00:58:43 2015 Antoine Baché
** Last update Tue Dec 15 01:00:46 2015 Antoine Baché
*/


#include "my.h"
#include <unistd.h>

int	pause_menu_actions(t_main_menu *menu)
{
  if (menu->options.select == 1)
    {
      write(1, "Go back to game !\n", 18);
      return (1);
    }
  else if (menu->options.select == 2)
    {
      write(1, "Go back to main menu !\n", 23);
      write(1, "/*\n** Main Menu\n*/\n", 19);
      return (2);
    }
  return (0);
}
