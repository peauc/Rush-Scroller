/*
** events.c for events in /home/wery_p/rendu/gfx_scroller/srcs/scroller_wolfs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 19 02:35:09 2016 Paul Wery
** Last update Sat Mar 19 11:34:40 2016 Paul Wery
*/

#include <lapin.h>
#include "demo.h"

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym keysym,
			    void *data UNUSED)
{
  if (state == GO_UP && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	loop(void *data)
{
  t_scroll		*s;

  s = (t_scroll*)data;
  bunny_blit(&s->win->buffer, &s->pix->clipable, NULL);
  bunny_display(s->win);
  return (GO_ON);
}

void	next_stage(t_scroll *s, t_win *w,
		   t_stage *list, t_stage *it)
{
  void	(*next_stage)(t_win *, t_stage *, t_stage *);

  if (it->next != list)
    {
      if ((*(void **)(&next_stage) = tekfunction(it->next->stage)) == NULL)
	return ;
      (*next_stage)(w, list, it->next);
    }
}

void	damier(t_win *w, t_stage *list,
	       t_stage *it)
{
  t_dam	d;

  bunny_set_loop_main_function(loop);
  bunny_set_key_response((t_bunny_key)key);
  bunny_loop(w->win, 0, &d);
  next->stage(&d, w, list, it);
}
