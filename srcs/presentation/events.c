/*
** events.c for events in /home/wery_p/rendu/gfx_scroller/srcs/scroller_wolfs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 19 02:35:09 2016 Paul Wery
** Last update Sat Mar 19 17:37:34 2016 
*/

#include <lapin.h>
#include "demo.h"

t_bunny_response	key_pres(t_bunny_event_state state,
				 t_bunny_keysym keysym,
				 void *data UNUSED)
{
  if (state == GO_UP && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	my_mouse(t_bunny_event_state state,
				 t_bunny_mouse_button but,
				 void *data UNUSED)
{
  const t_bunny_position	*click;

  if (but == BMB_LEFT && state == GO_DOWN)
    {
      click = bunny_get_mouse_position();
      if (click->x > WINL - 300 && click->x < WINL - 166
	  && click->y > WINH - 150 && click->y < WINH - 16)
	return (EXIT_ON_SUCCESS);
    }
  return (GO_ON);
}

t_bunny_response	loop_pres(void *data)
{
  t_text			*s;

  s = (t_text*)data;
  bunny_display(s->win);
  return (GO_ON);
}

void	presentation(t_win *w, t_stage *list,
		     t_stage *it)
{
  t_bunny_pixelarray	*image;
  t_bunny_position	pos;

  if ((image = bunny_load_pixelarray("map/wolf.jpg")) == NULL)
    return ;
  pos.x = WINL;
  pos.y = WINH;
  if ((image = resize_picture(image, pos)) == NULL)
    return ;
  bunny_blit(&w->win->buffer, &image->clipable, NULL);
  if ((image = bunny_load_pixelarray("map/buton.png")) == NULL)
    return ;
  pos.x = WINL - 300;
  pos.y = WINH - 150;
  bunny_blit(&w->win->buffer, &image->clipable, &pos);
  if ((image = bunny_load_pixelarray("map/text.png")) == NULL)
    return ;
  tektext(&w->win, "bonjour", image);
  bunny_set_loop_main_function(loop_pres);
  bunny_set_key_response((t_bunny_key)key_pres);
  bunny_set_click_response(&my_mouse);
  bunny_loop(w->win, 0, w);
  next_stage(w, list, it);
}
