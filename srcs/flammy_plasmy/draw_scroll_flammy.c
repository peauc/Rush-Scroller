/*
** draw_scroll_flammy.c for draw_scroll_flammy in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_scroller
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Sun Mar 20 18:34:59 2016
** Last update Sun Mar 20 18:48:47 2016 
*/

#include "demo.h"

void			draw_scroll(t_flame *data)
{
  static int		i;
  t_bunny_position	pos;

  pos.x = -1 + i;
  while (++pos.x < WINL)
    {
      pos.y = WINH - 120;
      while (++pos.y < WINH)
	tekpixel_int(data->pixel, &pos, BLACK);
    }
  i += 5;
}
