/*
** events.c for events in /home/wery_p/rendu/gfx_scroller/srcs/scroller_wolfs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 19 02:35:09 2016 Paul Wery
** Last update Sat Mar 19 07:38:22 2016 Paul Wery
*/

#include <lapin.h>
#include "demo.h"

t_bunny_response	key(t_bunny_event_state state UNUSED,
			    t_bunny_keysym keysym UNUSED,
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
  if (blit_pictures(s) == -1)
    return (EXIT_ON_ERROR);
  bunny_blit(&s->win->buffer, &s->pix->clipable, NULL);
  bunny_display(s->win);
  return (GO_ON);
}

void	delete_scroll(t_scroll *s)
{
  bunny_delete_clipable(&s->pix_one->clipable);
  bunny_delete_clipable(&s->pix_two->clipable);
  bunny_delete_clipable(&s->pix_three->clipable);
}

int	ini_scroll(t_scroll *s, t_win *w)
{
  s->win = w->win;
  s->pix = w->pix;
  if ((s->pix_one = bunny_load_pixelarray("map/montagnes.png")) == NULL)
    return (-1);
  s->speed_one = 0;
  s->start_one = 0;
  if ((s->pix_two = bunny_load_pixelarray("map/forêt.png")) == NULL)
    return (-1);
  s->speed_two = 0;
  s->start_two = 0;
  if ((s->pix_three = bunny_load_pixelarray("map/herbe.png")) == NULL)
    return (-1);
  s->speed_three = 0;
  s->start_three = 0;
  return (0);
}

void			scrolling(t_win *w, t_stage *list UNUSED,
				  t_stage *it UNUSED)
{
  t_bunny_position	pos;
  t_scroll		s;

  pos.x = WINL;
  pos.y = WINH * 1.1;
  if (ini_scroll(&s, w) == -1)
    return ;
  if ((s.pix_three = resize_picture(s.pix_three, pos)) == NULL)
    return ;
  pos.x = s.pix_two->clipable.clip_width * 2;
  pos.y = s.pix_two->clipable.clip_height * 2;
  if ((s.pix_two = resize_picture(s.pix_two, pos)) == NULL)
    return ;
  bunny_set_loop_main_function(loop);
  bunny_set_key_response((t_bunny_key)key);
  bunny_loop(w->win, 0, &s);
  delete_scroll(&s);
}
