/*
** fill.c for fill.c in /home/peau_c/rendu/LibLapin/gfx_fdf1
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:08:55 2015 clement peau
** Last update Sun Mar 20 11:45:19 2016 Clement Peau
*/

#include "default.h"

void		fill(t_bunny_pixelarray *pix, unsigned int col)
{
  int		n;
  t_color	*color;

  n = 0;
  while (n != (pix->clipable.clip_width * pix->clipable.clip_height))
    {
      color = (t_color*)pix->pixels + n;
      color->full = col;
      n++;
    }
}
