/*
** tekpixel.c for lol in /home/peau_c/rendu/LibLapin/gfx_fdf1
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Wed Nov 18 23:21:25 2015 clement peau
** Last update Sat Mar 19 19:34:12 2016 Clement Peau
*/

#include "rush_incendie.h"

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position pos,
		 t_color colo)
{
  t_color	*color;

  color =(t_color*)pix->pixels + pos.x + pos.y * WIDTH;
  color->full = colo.full;
}
