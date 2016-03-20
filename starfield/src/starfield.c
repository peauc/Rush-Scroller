/*
** SCRIPT
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Sun Mar 20 13:46:53 2016 Clement Peau
*/

#include "default.h"

t_star			*init_starfield(t_bunny_pixelarray *pix, int nb,
					int mode)
{
  t_star		*star;
  int			i;

  i = 0;
  if ((star = malloc(nb * sizeof(t_star))) == NULL)
    return (NULL);
  while (i < nb)
    {
      star[i].y = rand() % pix->clipable.clip_height;
      star[i].x = rand() % pix->clipable.clip_width;
      if (rand() % 2 == 0)
	star[i].x_speed = rand() % 10;
      else
	star[i].x_speed = - (rand() % 10);
      if (rand() % 2 == 0)
	star[i].y_speed = rand() % 10;
      else
	star[i].y_speed = - (rand() % 10);
      i++;
    }
  return (star);
}

void			starfield(t_bunny_pixelarray *pix, t_star *star, int nb)
{
  int			i;
  t_bunny_position	pos;
  t_color		color;

  color.full = WHITE;
  i = 0;
  while (i < nb)
    {
      star[i].x -= star[i].x_speed;
      if (star[i].x < 0)
	{
	  star[i].x = pix->clipable.clip_width - 1;
	  star[i].y = rand() % pix->clipable.clip_height - 1;
	}
      if (star[i].x > pix->clipable.clip_width)
	{
	  star[i].x = 0;
	  star[i].y = rand() % pix->clipable.clip_height - 1;
	}
      pos.x = star[i].x;
      pos.y = star[i].y;
      tekpixel(pix, &pos, &color, 0);
      i++;
    }
}
