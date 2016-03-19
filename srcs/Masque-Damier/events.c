/*
** events.c for events in /home/wery_p/rendu/gfx_scroller/srcs/scroller_wolfs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 19 02:35:09 2016 Paul Wery
** Last update Sat Mar 19 14:10:07 2016 Paul Wery
*/

#include <lapin.h>
#include "demo.h"

t_bunny_response	keyi(t_bunny_event_state state,
			     t_bunny_keysym keysym,
			     void *data UNUSED)
{
  if (state == GO_UP && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	loopi(void *data)
{
  t_dam			*d;

  d = (t_dam*)data;
  bunny_blit(&d->win->buffer, &d->pix->clipable, NULL);
  bunny_display(d->win);
  return (GO_ON);
}

void	next_stage(t_dam *d, t_win *w,
		   t_stage *list, t_stage *it)
{
  void	(*next_stage)(t_win *, t_stage *, t_stage *);

  bunny_delete_clipable(&d->filter->clipable);
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

  if ((d.filter = bunny_new_pixelarray(WINL, WINH)) == NULL)
    return ;
  bunny_set_loop_main_function(loopi);
  bunny_set_key_response((t_bunny_key)keyi);
  bunny_loop(w->win, 0, &d);
  next_stage(&d, w, list, it);
}
