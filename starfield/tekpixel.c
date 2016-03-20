/*
** tekpixel.c for tekpixel in /home/wery_p/rendu/gfx_scroller/srcs/scroller_wolfs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 19 03:21:06 2016 Paul Wery
** Last update Sat Mar 19 06:44:08 2016 Paul Wery
*/

#include <lapin.h>

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color *color,
			 int state)
{
  t_color	*pixel;
  int		i;

  if (pos->x >= 0 && pos->x < pix->clipable.clip_width &&
      pos->y >= 0 && pos->y < pix->clipable.clip_height)
    {
      i = pos->x + (pix->clipable.clip_width * pos->y);
      pixel = (t_color*)pix->pixels + i;
      if (color->argb[3] > 0 && (color->full != 0xFFFFFFFF
				 || state != 1))
	pixel->full = color->full;
    }
}
