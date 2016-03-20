/*
** tekpixel.c for tekpixel in /home/mmaud/Rendu/Semestre_2/Infographie/gfx_tekgui
**
** Made by Maud MAREL
** Login   <marel_m@epitech.net>
**
** Started on  Mon Feb  8 10:13:33 2016 Maud MAREL
** Last update Sun Mar 20 14:17:11 2016 
*/

#include <lapin.h>
#include "demo.h"

void		tekpixel_int(t_bunny_pixelarray *pix,
			     t_bunny_position *pos,
			     unsigned int color)
{
  t_color       *col;

  col = (t_color*)pix->pixels
    + (pos->x + pos->y * pix->clipable.clip_width);
  col->full = color;
}
