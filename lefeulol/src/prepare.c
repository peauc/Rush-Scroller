/*
** prepare.c for prapae in /home/peau_c/rendu/LibLapin/gfx_fdf1
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Fri Nov 20 16:50:11 2015 clement peau
** Last update Sat Nov 21 12:31:45 2015 clement peau
*/

#include "../include/struct.h"

void	prepare(t_bunny_pixelarray *pix)
{
  pix->clipable.clip_width = 1920;
  pix->clipable.clip_height = 1080;
  fill(pix);
}
