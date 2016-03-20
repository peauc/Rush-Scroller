/*
** tekpix.c for tekpix in
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Mar 20 16:25:36 2016 Paul Wery
** Last update Sun Mar 20 16:32:27 2016 Paul Wery
*/

#include <lapin.h>

void		tekpix(t_bunny_pixelarray *pix,
		       t_bunny_position *pos,
		       t_color *color)
{
  t_color	*pixel;
  int		i;

  if (pos->x >= 0 && pos->x < pix->clipable.clip_width &&
      pos->y >= 0 && pos->y < pix->clipable.clip_height)
    {
      i = pos->x + (pix->clipable.clip_width * pos->y);
      pixel = (t_color*)pix->pixels + i;
      pixel->full = color->full;
    }
}
