/*
** frontal.c for frontal in /home/peau_c/rendu/Lib/gfx_scroller/starfield
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Sun Mar 20 13:20:17 2016 Clement Peau
** Last update Sun Mar 20 13:44:32 2016 Clement Peau
*/

#include "default.h"

void			frontal_stars(t_bunny_pixelarray *pix, t_star *star,
				      int nb)
{
  int			i;
  t_bunny_position	pos;
  t_color		color;

  color.full = WHITE;
  i = 0;
  while (i < nb)
    {
      star[i].x -= star[i].x_speed;
      star[i].y -= star[i].y_speed;
      if (star[i].x < 0 || star[i].x > pix->clipable.clip_width ||
	  star[i].y < 0 || star[i].y > pix->clipable.clip_height)
	{
	  star[i].x = pix->clipable.clip_width / 2 + rand() % 50;
	  star[i].y = pix->clipable.clip_height / 2 + rand() % 50;
	}
      pos.x = star[i].x;
      pos.y = star[i].y;
      tekpixel(pix, &pos, &color, 0);
      i++;
    }
}
