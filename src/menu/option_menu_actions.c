/*
** option_menu_actions.c for gfx_wolf3d in /gfx_wolf3d/src/menu
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 13 13:10:28 2015 Antoine Baché
** Last update Sun Dec 13 14:11:43 2015 Antoine Baché
*/


#include "my.h"
#include <unistd.h>

int	option_menu_actions(t_main_menu *menu)
{
  if (menu->options.select == 1)
    {
      write(1, "Toggle music !\n", 15);
      menu->options.music = ((menu->options.music == 1) ? 0 : 1);
    }
  else if (menu->options.select == 2)
    {
      write(1, "Go back to main menu !\n", 23);
      write(1, "/*\n** Main Menu\n*/\n", 19);
      return (1);
    }
  return (0);
}