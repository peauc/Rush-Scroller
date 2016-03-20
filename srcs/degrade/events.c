/*
** events.c for events in
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Mar 20 16:46:05 2016 Paul Wery
** Last update Sun Mar 20 17:35:30 2016 Paul Wery
*/

#include <lapin.h>
#include "demo.h"

t_bunny_response	keys(t_bunny_event_state state,
			     t_bunny_keysym keysym,
			     void *data)
{
  t_win			*w;

  w = (t_win*)data;
  if (state == GO_UP && keysym == BKS_ESCAPE)
    {
      w->exit = 1;
      return (EXIT_ON_SUCCESS);
    }
  return (GO_ON);
}

t_bunny_response	loops(void *data)
{
  t_win			*w;

  w = (t_win*)data;
  if (degraded(w) == 1)
    return (EXIT_ON_SUCCESS);
  bunny_blit(&w->win->buffer, &w->pix->clipable, NULL);
  bunny_display(w->win);
  return (GO_ON);
}

void			deg(t_win *w, t_stage *list,
			    t_stage *it)
{
  w->exit = 0;
  bunny_set_loop_main_function(loops);
  bunny_set_key_response((t_bunny_key)keys);
  bunny_loop(w->win, 0, w);
  if (w->exit == 0)
    next_stage(w, list, it);
}
