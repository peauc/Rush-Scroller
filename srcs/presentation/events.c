/*
** events.c for events in /home/wery_p/rendu/gfx_scroller/srcs/scroller_wolfs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 19 02:35:09 2016 Paul Wery
** Last update Sun Mar 20 21:03:42 2016 Poc
*/

#include <lapin.h>
#include "demo.h"

t_bunny_response	key_pres(t_bunny_event_state state,
				 t_bunny_keysym keysym,
				 void *data)
{
  t_win			*w;

  w = (t_win*)data;
  if (state == GO_UP && keysym == BKS_ESCAPE)
    {
      w->exit = 1;
      return (EXIT_ON_ERROR);
    }
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
  t_win		*w;
  t_bunny_position	pos;

  w = (t_win*)data;
  pix_initialize(w->pix);
  pix_initialize(w->text->pix);
  write_name(w);
  play_sound(w->song);
  write_title_push(w);
  pos.x = 0;
  pos.y = 0;
  put_pix_in_pix_txt(w->pix, w->text->back, pos);
  put_pix_in_pix_txt(w->pix, w->text->pix, pos);
  bunny_blit(&w->win->buffer, &w->pix->clipable, NULL);
  bunny_display(w->win);
  return (GO_ON);
}

int	init_struc_text(t_win *w)
{
  t_bunny_position	pos;

  if ((w->text = malloc(sizeof(t_text))) == NULL)
    return (-1);
  if ((w->text->back = bunny_load_pixelarray("map/pres.png")) == NULL)
    return (-1);
  if ((w->text->font_png = bunny_load_pixelarray("map/text.png")) == NULL)
    return (-1);
  pos.x = WINL;
  pos.y = WINH;
  if ((w->text->back = resize_picture(w->text->back, pos)) == NULL)
    return (-1);
  if ((w->text->pix = bunny_new_pixelarray(WINL, WINH)) == NULL)
    return (-1);
  w->text->start1.x = 0;
  w->text->start1.y = 300;
  w->text->start2.x = 0;
  w->text->start2.y = 400;
  w->text->start3.x = -150;
  w->text->start3.y = 825;
  return (0);
}

void	presentation(t_win *w, t_stage *list,
		     t_stage *it)
{
  w->exit = 0;
  init_struc_text(w);
  if (init_struc_text(w) == -1)
    return ;
  if ((w->song = sound()) == NULL)
    return ;
  bunny_set_loop_main_function(loop_pres);
  bunny_set_key_response((t_bunny_key)key_pres);
  bunny_set_click_response(&my_mouse);
  bunny_loop(w->win, 60, w);
  bunny_delete_clipable(&w->text->back->clipable);
  bunny_delete_clipable(&w->text->font_png->clipable);
  if (w->exit == 0)
    next_stage(w, list, it);
}
