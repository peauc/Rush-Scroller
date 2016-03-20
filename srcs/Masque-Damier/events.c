/*
** events.c for events in /home/wery_p/rendu/gfx_scroller/srcs/scroller_wolfs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 19 02:35:09 2016 Paul Wery
** Last update Sun Mar 20 17:24:59 2016 Paul Wery
*/

#include <lapin.h>
#include "demo.h"

t_bunny_response	keyi(t_bunny_event_state state,
			     t_bunny_keysym keysym,
			     void *data)
{
  t_dam			*d;

  d = (t_dam*)data;
  if (state == GO_UP && keysym == BKS_ESCAPE)
    {
      d->exit = 1;
      return (EXIT_ON_SUCCESS);
    }
  if (state == GO_UP && keysym == BKS_RETURN)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	loopi(void *data)
{
  static int		turn = 0;
  t_dam			*d;

  d = (t_dam*)data;
  if (turn == 0)
    dam(d);
  else if (turn == 35)
    dam_two(d);
  bunny_blit(&d->win->buffer, &d->pix->clipable, NULL);
  bunny_display(d->win);
  turn += 1;
  if (turn == 36)
    turn = 0;
  return (GO_ON);
}

void	next_stage(t_win *w, t_stage *list, t_stage *it)
{
  void	(*next_stage)(t_win *, t_stage *, t_stage *);

  if (it->next != list)
    {
      if ((*(void **)(&next_stage) = tekfunction(it->next->stage)) == NULL)
	return ;
      (*next_stage)(w, list, it->next);
    }
}

void			damier(t_win *w, t_stage *list,
			       t_stage *it)
{
  t_dam			d;
  t_bunny_position	pos;

  pos.x = WINL;
  pos.y = WINH;
  d.win = w->win;
  d.exit = 0;
  bunny_delete_clipable(&w->pix->clipable);
  if ((w->pix = bunny_load_pixelarray("map/dragon.jpeg")) == NULL)
    return ;
  if ((w->pix = resize_picture(w->pix, pos)) == NULL)
    return ;
  if ((d.filter = bunny_new_pixelarray(WINL, WINH)) == NULL)
    return ;
  d.pix = w->pix;
  bunny_set_loop_main_function(loopi);
  bunny_set_key_response((t_bunny_key)keyi);
  bunny_loop(w->win, 0, &d);
  bunny_delete_clipable(&d.filter->clipable);
  if (d.exit == 0)
    next_stage(w, list, it);
}
