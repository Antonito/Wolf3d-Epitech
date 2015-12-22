/*
** main_menu_actions.c for gfx_wolf3d in /gfx_wolf3d/src/menu
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Dec 13 01:38:46 2015 Antoine Baché
** Last update Tue Dec 22 19:19:14 2015 Antoine Baché
*/

#include "my.h"

int	main_menu_actions(t_main_menu *menu)
{
  if (menu->select == 1 && wolf(menu) == 1)
    return (1);
  else if (menu->select == 2 && option_menu(menu) == 1)
    return (1);
  else if (menu->select == 3)
    return (2);
  return (0);
}
