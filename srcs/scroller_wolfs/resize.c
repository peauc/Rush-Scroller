/*
** resize.c for resize in /home/wery_p/rendu/flip_part_2020
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Feb 22 14:13:05 2016 Paul Wery
** Last update Sat Mar 19 06:24:26 2016 Paul Wery
*/

#include <lapin.h>
#include "demo.h"

void	ini_resize(t_resize *r)
{
  r->x_one = 0;
  r->y_one = 0;
  r->x_two = 0;
  r->y_two = 0;
}

void	main_full_new_pix(t_bunny_pixelarray *pix,
			  t_bunny_pixelarray *new_pix,
			  t_resize *r)
{
  r->i = (int)(r->x_one + (r->y_one * new_pix->clipable.clip_width));
  r->color = (t_color*)new_pix->pixels + r->i;
  r->i = (int)(r->x_two + (r->y_two * pix->clipable.clip_width));
  r->pixel = (t_color*)pix->pixels + r->i;
  r->color->full = r->pixel->full;
  r->x_one += 1;
}

void	       	full_new_pix(t_bunny_pixelarray *pix,
			     t_bunny_pixelarray *new_pix,
			     t_my_scale *s_one)
{
  t_resize	r;

  ini_resize(&r);
  while (r.y_one < new_pix->clipable.clip_height)
    {
      while (r.y_one < ((r.y_two + 1) * s_one->scale_y))
	{
	  while (r.x_one < new_pix->clipable.clip_width)
	    {
	      while (r.x_one < ((r.x_two + 1) * s_one->scale_x))
		main_full_new_pix(pix, new_pix, &r);
	      r.x_two += 1;
	    }
	  r.x_one = 0;
	  r.x_two = 0;
	  r.y_one += 1;
	}
      r.y_two += 1;
    }
}

t_bunny_pixelarray	*resize(t_bunny_pixelarray *pix,
				t_bunny_position pos)
{
  t_bunny_pixelarray	*new_pix;
  t_my_scale		s_one;

  if ((new_pix = bunny_new_pixelarray(pos.x * 128, pos.y)) == NULL)
    return (NULL);
  pix_initialize(new_pix);
  s_one.scale_x = (double)new_pix->clipable.clip_width /
    (double)pix->clipable.clip_width;
  s_one.scale_y = (double)new_pix->clipable.clip_height /
    (double)pix->clipable.clip_height;
  full_new_pix(pix, new_pix, &s_one);
  bunny_delete_clipable(&pix->clipable);
  return (new_pix);
}

t_bunny_pixelarray	*resize_picture(t_bunny_pixelarray *pix,
					t_bunny_position pos)
{
  t_bunny_pixelarray	*new_pix;
  t_my_scale		s_one;

  if ((new_pix = bunny_new_pixelarray(pos.x, pos.y)) == NULL)
    return (NULL);
  pix_initialize(new_pix);
  s_one.scale_x = (double)new_pix->clipable.clip_width /
    (double)pix->clipable.clip_width;
  s_one.scale_y = (double)new_pix->clipable.clip_height /
    (double)pix->clipable.clip_height;
  full_new_pix(pix, new_pix, &s_one);
  bunny_delete_clipable(&pix->clipable);
  return (new_pix);
}
