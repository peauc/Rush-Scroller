/*
** main.c for main in /home/peau_c/rendu/LibLapin/gfx_fdf1
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Sun Mar 20 19:59:36 2016 Poc
*/

#include "demo.h"

t_bunny_response	escape_flag(t_bunny_event_state state,
				    t_bunny_keysym key,
				    void *data)
{
  t_win			*win;

  win = (t_win*)data;
  if (key == BKS_ESCAPE && state == GO_DOWN)
    {
      win->exit = 1;
      return (EXIT_ON_SUCCESS);
    }
  if (key == BKS_RETURN)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response       	mainloop_flag(t_flag *data)
{
  fill(data->pixelarray);
  data->modifier += 1;
  cpy_pix(data->pixel, data->pixelarray, data->modifier);
  bunny_blit(&data->window->buffer, &data->pixelarray->clipable, NULL);
  bunny_display(data->window);
  return (GO_ON);
}

void			flag(t_win *w, t_stage *list, t_stage *it)
{
  t_flag		data;

  w->exit = 0;
  data.modifier = 0;
  if ((data.window = bunny_start(1200, 1000, false, "flaggyflaggy")) == NULL)
    return ;
  if ((data.pixel = bunny_load_pixelarray("map/flag.png")) == NULL)
    return ;
  if ((data.pixelarray = bunny_new_pixelarray(1200, 1000)) == NULL)
    return ;
  bunny_set_loop_main_function((t_bunny_loop)mainloop_flag);
  bunny_set_key_response((t_bunny_key)&escape_flag);
  if (bunny_loop(data.window, 60, &data) == 0)
    return ;
  bunny_stop(data.window);
  bunny_delete_clipable(&data.pixel->clipable);
  if (w->exit == 0)
    next_stage(w, list, it);
}
