/*
** calc.c for calc in /home/peau_c/fantasy2_2020/sujet1
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Thu Jan 14 00:16:29 2016
** Last update Sun Mar 20 19:29:09 2016 Marel la plus belle <3
*/

#include "demo.h"

void			cpy_pix(t_bunny_pixelarray *src,
				t_bunny_pixelarray *dest,
				double data_modifier)
{
  int			i;
  int			j;
  t_color		*color;
  t_bunny_position	pos;
  double		modifier;

  i = 0;
  j = 0;
  while (i != src->clipable.clip_width)
    {
      modifier = sin ((i + data_modifier) / 40.000) * 8;
      while (j != src->clipable.clip_height)
	{
	  color = (t_color *)src->pixels + src->clipable.clip_width
	    * j + i;
	  pos.x = i + DEST_WIDTH / 2 - SRC_WIDTH / 2;
	  pos.y = (j + DEST_HEIGHT / 2 - SRC_HEIGHT / 2) - modifier;
	  tekpixel_int(dest, &pos, color->full);
	  j++;
	}
      j = 0;
      i++;
    }
}
