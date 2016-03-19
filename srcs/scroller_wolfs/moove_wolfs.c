/*
** moove_wolfs.c for moove_wolfs in /home/wery_p/rendu/gfx_scroller/srcs/scroller_wolfs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 19 09:05:38 2016 Paul Wery
** Last update Sat Mar 19 10:28:03 2016 Paul Wery
*/

#include <lapin.h>
#include "demo.h"

void			wolf(t_scroll *s, t_bunny_position pos,
			     t_bunny_position posi)
{
  t_bunny_position	end;
  t_color		*color;
  int			i;

  end.x = pos.x + 200;
  end.y = pos.y + 200;
  while (pos.y < end.y)
    {
      while (pos.x < end.x)
	{
	  i = posi.x + (posi.y * s->wolf->clipable.clip_width);
	  color = (t_color*)s->wolf->pixels + i;
	  tekpixel(s->pix, &pos, color, 0);
	  pos.x += 1;
	  posi.x += 1;
	}
      pos.x = end.x - 200;
      posi.x = s->sprite_wolf * 200;
      pos.y += 1;
      posi.y += 1;
    }
}

void			moove_wolf(t_scroll *s)
{
  static int		turn = 0;
  t_bunny_position	pos;
  t_bunny_position	posi;

  pos.x = s->start_wolf;
  pos.y = WINH - 250;
  posi.x = s->sprite_wolf * 200;
  posi.y = s->state_wolf * 200;
  wolf(s, pos, posi);
  if (turn == 1)
    s->sprite_wolf += 1;
  turn += 1;
  if (turn == 2)
    turn = 0;
  if (s->state_wolf == 1)
    s->start_wolf += 3;
  else if (s->state_wolf == 0)
    s->start_wolf -= 3;
  if ((s->sprite_wolf == 4 && s->state_wolf != 2) ||
      (s->sprite_wolf == 3 && s->state_wolf == 2))
    s->sprite_wolf = 0;
}
