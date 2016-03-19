/*
** events.c for events in /home/wery_p/rendu/gfx_scroller/srcs/scroller_wolfs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 19 02:35:09 2016 Paul Wery
** Last update Sat Mar 19 14:56:35 2016 
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

void	presentation(t_win *w, t_stage *list,
		     t_stage *it)
{
  t_dam	d;
  t_bunny_pixelarray	*image;
  t_bunny_position	pos;

  if ((image = bunny_load_pixelarray("map/wolf.jpg")) == NULL)
    return ;
  pos.x = WINL;
  pos.y = WINH;
  if ((image = resize_picture(image, pos)) == NULL)
    return ;
  bunny_blit(&w->win->buffer, &w->pix->clipable, NULL);
  bunny_set_loop_main_function(loop);
  bunny_set_key_response((t_bunny_key)key);
  bunny_loop(w->win, 0, &d);
  next->stage(&d, w, list, it);
}
