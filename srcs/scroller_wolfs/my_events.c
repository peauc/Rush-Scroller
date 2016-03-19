/*
** my_events.c for my_events in /home/wery_p/rendu/gfx_scroller/srcs/scroller_wolfs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 19 18:49:18 2016 Paul Wery
** Last update Sat Mar 19 18:56:50 2016 Paul Wery
*/

#include <lapin.h>
#include "demo.h"

void	events_wolf(t_scroll *s, t_bunny_event_state state,
		    t_bunny_keysym keysym)
{
  if (state == GO_UP && keysym == BKS_K)
    {
      s->sprite_wolf = 0;
      s->state_wolf = 0;
    }
  else if (state == GO_UP && keysym == BKS_L)
    {
      s->sprite_wolf = 0;
      s->state_wolf = 2;
    }
  else if (state == GO_UP && keysym == BKS_M)
    {
      s->sprite_wolf = 0;
      s->state_wolf = 1;
    }
  else if (state == GO_UP && keysym == BKS_SPACE)
    s->next = 1;
  else if (state == GO_UP && keysym == 10)
    s->next_stage = 1;
}
