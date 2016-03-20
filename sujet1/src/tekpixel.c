/*
** tekpixel.c for lol in /home/peau_c/rendu/LibLapin/gfx_fdf1
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Wed Nov 18 23:21:25 2015 clement peau
** Last update Thu Jan 14 00:52:24 2016 
*/

#include "struct.h"

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position pos,
		 unsigned int col)
{
  t_color *color;

  if ((pos.x * pos.y) < (1000 *
			   1000))
    {
      color =(t_color*)pix->pixels + pos.x + pos.y * pix->clipable.clip_width;
      color->full = col;
    }
}
