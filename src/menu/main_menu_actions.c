/*
** main_menu_actions.c for gfx_wolf3d in /gfx_wolf3d/src/menu
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 13 01:38:46 2015 Antoine Baché
** Last update Sun Dec 13 01:51:05 2015 Antoine Baché
*/

#include "my.h"
#include <unistd.h>

int	main_menu_actions(t_main_menu *menu)
{
  if (menu->select == 1)
    write(1, "Start Game !\n", 14);
  else if (menu->select == 2)
    write(1, "Open menu option !\n", 20);
  else
    return (1);
  return (0);
}