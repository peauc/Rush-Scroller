/*
** blit_pictures.c for blit_pictures in /home/wery_p/rendu/gfx_scroller/srcs/scroller_wolfs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 19 03:20:15 2016 Paul Wery
** Last update Sat Mar 19 16:32:08 2016 Paul Wery
*/

#include <lapin.h>
#include "demo.h"

void	actualize_pos(t_bunny_position *posi,
		      int state)
{
  if (state == 0)
    posi->x += 1;
  else if (state == 1)
    posi->x -= 1;
}

void			put_pix_in_pix(t_scroll *s,
				       t_bunny_pixelarray *src,
				       t_bunny_position pos,
				       int start)
{
  static int		state = 0;
  t_bunny_position	posi;
  t_color		*color;
  int			i;

  posi.x = start;
  posi.y = 0;
  state = 0;
  while (pos.y < WINH && posi.y < src->clipable.clip_height)
    {
      state = 0;
      while (pos.x < WINL)
	{
	  i = posi.x + (posi.y * src->clipable.clip_width);
	  color = (t_color*)src->pixels + i;
	  tekpixel(s->pix, &pos, color, s->state);
	  pos.x += 1;
	  actualize_pos(&posi, state);
	  if (posi.x == (src->clipable.clip_width -1))
	    state = 1;
	  else if (posi.x == 0)
	    state = 0;
	}
      pos.x = 0;
      pos.y += 1;
      if (state == 0)
	posi.x = start;
      posi.y += 1;
    }
}

void		pix_initialize(t_bunny_pixelarray *pix)
{
  t_color	*color;
  int		n;
  int		i;

  n = 0;
  i = pix->clipable.clip_width * pix->clipable.clip_height;
  while (n < i)
    {
      color = (t_color*)pix->pixels + n;
      color->full = 0x00000000;
      n += 1;
    }
}

void	actualize_start(t_scroll *s)
{
  s->start_one += 1;
  if (s->start_one == s->pix_one->clipable.clip_width)
    s->start_one = 0;
  s->start_two += 2;
  if (s->start_two == s->pix_two->clipable.clip_width)
    s->start_two = 0;
  s->start_three += 3;
  if (s->start_three == s->pix_three->clipable.clip_width)
    s->start_three = 0;
}

int			blit_pictures(t_scroll *s)
{
  t_bunny_position	pos;

  pix_initialize(s->pix);
  pos.x = 0;
  pos.y = 0;
  s->state = 0;
  put_pix_in_pix(s, s->pix_one, pos, s->start_one);
  pos.y = WINH - s->pix_three->clipable.clip_height;
  s->state = 1;
  put_pix_in_pix(s, s->pix_three, pos, s->start_three);
  pos.y = WINH - s->pix_two->clipable.clip_height - (WINH / 4);
  s->state = 2;
  put_pix_in_pix(s, s->pix_two, pos, s->start_two);
  actualize_start(s);
  return (0);
}
