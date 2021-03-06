/*
** events.c for events in /home/wery_p/rendu/gfx_scroller/srcs/scroller_wolfs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 19 02:35:09 2016 Paul Wery
** Last update Sun Mar 20 20:58:51 2016 Poc
*/

#include <lapin.h>
#include "demo.h"

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym keysym,
			    void *data)
{
  t_scroll		*s;

  s = (t_scroll*)data;
  if (state == GO_UP && keysym == BKS_ESCAPE)
    {
      s->exit = 1;
      return (EXIT_ON_SUCCESS);
    }
  if (state == GO_UP && keysym == BKS_RETURN)
    return (EXIT_ON_SUCCESS);
  events_wolf(s, state, keysym);
  return (GO_ON);
}

t_bunny_response	loop(void *data)
{
  t_scroll		*s;

  s = (t_scroll*)data;
  blit_pictures(s);
  if (s->next == 1)
    moove_wolf(s);
  bunny_blit(&s->win->buffer, &s->pix->clipable, NULL);
  bunny_display(s->win);
  return (GO_ON);
}

void	delete_scroll(t_scroll *s, t_win *w,
		      t_stage *list, t_stage *it)
{
  void	(*next_stage)(t_win *, t_stage *, t_stage *);

  bunny_delete_clipable(&s->pix_one->clipable);
  bunny_delete_clipable(&s->pix_two->clipable);
  bunny_delete_clipable(&s->pix_three->clipable);
  bunny_delete_clipable(&s->wolf->clipable);
  bunny_delete_clipable(&s->pix_sol->clipable);


  if (it->next != list)
    {
      if ((*(void **)(&next_stage) = tekfunction(it->next->stage)) == NULL)
	return ;
      if (s->exit == 0)
	(*next_stage)(w, list, it->next);
    }
}


int	ini_scroll(t_scroll *s, t_win *w)
{
  s->win = w->win;
  s->pix = w->pix;
  if ((s->pix_one = bunny_load_pixelarray("map/montagnes.png")) == NULL)
    return (-1);
  s->start_one = 0;
  if ((s->pix_two = bunny_load_pixelarray("map/tree.png")) == NULL)
    return (-1);
  if ((s->pix_sol = bunny_load_pixelarray("map/terre.jpg")) == NULL)
    return (-1);
  s->start_two = 0;
  if ((s->pix_three = bunny_load_pixelarray("map/herbe.png")) == NULL)
    return (-1);
  s->start_three = 0;
  if ((s->wolf = bunny_load_pixelarray("map/wolf.png")) == NULL)
    return (-1);
  s->state_wolf = 1;
  s->sprite_wolf = 0;
  s->start_wolf = -200;
  s->state = 0;
  s->next = 0;
  s->next_stage = 0;
  s->exit = 0;
  return (0);
}

void			scrolling(t_win *w, t_stage *list,
				  t_stage *it)
{
  t_bunny_position	pos;
  t_scroll		s;

  pos.x = WINL;
  pos.y = WINH * 1.1;
  if (ini_scroll(&s, w) == -1)
    return ;
  if ((s.pix_three = resize_picture(s.pix_three, pos)) == NULL)
    return ;
  pos.x = s.wolf->clipable.clip_width * 2;
  pos.y = s.wolf->clipable.clip_height * 2;
  if ((s.wolf = resize_picture(s.wolf, pos)) == NULL)
    return ;
  pos.x = s.pix_two->clipable.clip_width * 1.5;
  pos.y = s.pix_two->clipable.clip_height * 1.5;
  if ((s.pix_two = resize_picture(s.pix_two, pos)) == NULL)
    return ;
  pos.x = WINL / 5;
  pos.y = WINH / 4.5;
  if ((s.pix_sol = resize_picture(s.pix_sol, pos)) == NULL)
    return ;
  bunny_set_loop_main_function(loop);
  bunny_set_key_response((t_bunny_key)key);
  bunny_loop(w->win, 0, &s);
  delete_scroll(&s, w, list, it);
}
