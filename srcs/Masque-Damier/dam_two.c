/*
** dam.c for dam in /home/wery_p/rendu/gfx_scroller/srcs/Masque-Damier
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 19 13:49:55 2016 Paul Wery
** Last update Sat Mar 19 18:36:08 2016 Paul Wery
*/

#include <lapin.h>
#include "demo.h"

void			negative_fourth(t_dam *d, int width, int height,
					t_bunny_position size)
{
  t_color		*color;
  t_bunny_position	pos;

  pos.x = WINL - 1;
  pos.y = WINH - 1;
  while (pos.y >= 0)
    {
      color = (t_color*)d->pix->pixels + (pos.x + (pos.y * WINL));
      if (size.y < height && size.x > width)
	reverse_color(color);
      pos.x -= 1;
      size.x += 1;
      if (pos.x == 0)
        {
          pos.x = WINL - 1;
          pos.y -= 1;
	  size.y += 1;
        }
      if (size.x == (2 * width))
	size.x = 0;
      if (size.y == (2 * height))
	size.y = 0;
    }
}

void			negative_three(t_dam *d, int width, int height,
				       t_bunny_position size)
{
  t_color		*color;
  t_bunny_position	pos;

  pos.x = WINL - 1;
  pos.y = WINH - 1;
  while (pos.y >= 0)
    {
      color = (t_color*)d->pix->pixels + (pos.x + (pos.y * WINL));
      if (size.y > height && size.x < width)
	reverse_color(color);
      pos.x -= 1;
      size.x += 1;
      if (pos.x == 0)
        {
          pos.x = WINL - 1;
          pos.y -= 1;
	  size.y += 1;
        }
      if (size.x == (2 * width))
	size.x = 0;
      if (size.y == (2 * height))
	size.y = 0;
    }
}

void			dam_two(t_dam *d)
{
  t_bunny_position	size;
  int			size_width;
  int			size_height;

  size.x = 0;
  size.y = 0;
  size_width = WINL / 10;
  size_height = WINH / 10;
  negative_three(d, size_width, size_height, size);
  negative_fourth(d, size_width, size_height, size);
}
