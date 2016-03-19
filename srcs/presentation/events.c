/*
** events.c for events in /home/wery_p/rendu/gfx_scroller/srcs/scroller_wolfs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 19 02:35:09 2016 Paul Wery
** Last update Sun Mar 20 00:06:21 2016 
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
  t_win			*w;
  t_text		*t;
  t_bunny_position	pos;

  w = (t_win*)data;
  t = (t_text*)data;
  tektext(t, w->pix, "rush troller");
  pos.x = 0;
  pos.y = 0;
  t->start->x++;
  put_pix_in_pix_txt(t->back, w->pix, pos);
  bunny_blit(&w->win->buffer, &t->back->clipable, NULL);
  bunny_display(w->win);
  return (GO_ON);
}

void	init_struc_text(t_text *text)
{
  t_bunny_position	pos;
  if ((text->back = bunny_load_pixelarray("map/pres.png")) == NULL)
    return ;
  if ((text->font_png = bunny_load_pixelarray("map/text.png")) == NULL)
    return ;
  pos.x = WINL;
  pos.y = WINH;
  if ((text->back = resize_picture(text->back, pos)) == NULL)
    return ;
  text->start->x = 0;
  text->start->y = 100;
}

void	presentation(t_win *w, t_stage *list,
		     t_stage *it)
{
  t_text		text;

  init_struc_text(&text);
  pix_initialize_txt(w->pix);
  bunny_set_loop_main_function(loop_pres);
  bunny_set_key_response((t_bunny_key)key_pres);
  bunny_set_click_response(&my_mouse);
  bunny_loop(w->win, 0, w);
  next_stage(w, list, it);
}
