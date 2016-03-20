/*
** fill.c for fill in /home/peau_c/fantasy2_2020/sujet1
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Thu Jan 14 01:10:48 2016
** Last update Thu Jan 14 01:20:12 2016 
*/

#include "struct.h"

void		fill(t_bunny_pixelarray *pix)
{
  int		i;
  t_color	*color;

  i = 0;
  while (i < pix->clipable.clip_width * pix->clipable.clip_height)
    {
      color = (t_color *)pix->pixels + i;
      color->full = BLACK;
      i++;
    }
}
