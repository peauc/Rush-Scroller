/*
** main.c for main in /home/peau_c/rendu/LibLapin/gfx_fdf1
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Sun Mar 20 19:03:51 2016 Clement Peau
*/

#include "plasma.h"

t_bunny_response	escape(t_bunny_event_state state,
			       t_bunny_keysym key,
			       void *data)
{
  state = state;
  data = data;
  if (key == BKS_ESCAPE)
    {
      data->win->exit = 1;
      return (EXIT_ON_SUCCESS);
    }
  if (key == BKS_RETURN)
    return (EXIT_ON_SUCCESS)
  return (GO_ON);
}

int			splited_main(t_data *data)
{
  data->plasma += 0.2;
  if (data->plasma > 5)
    data->plasma = 0.1;
  plasma(data);
}

t_bunny_response       	mainloop(void *tmp)
{
  t_data		*data;

  data = tmp;
  if (splited_main(data) == 0)
    return (0);
  bunny_blit(&data->window->buffer, &data->pixel->clipable, NULL);
  bunny_display(data->window);
  return (GO_ON);
}

int			plasmy_plasmy(t_win *win, t_stage *stage, t_stage *in)
{
  t_data		data;

  data->win = win;
  win->exit = 0;
  data.window = bunny_start(1920, 1080, false, "test");
  data.pixel = bunny_new_pixelarray(1920, 1080);
  fillplasma(data.pixel);
  tab_setting(&data);
  data.color = colorplasma();
  data.boole = 0;
  bunny_set_loop_main_function(mainloop);
  bunny_set_key_response(&escape);
  if (bunny_loop(data.window, 20, &data) == 0)
    return (0);
  bunny_free(data.tab);
  bunny_free(data.color);
  bunny_delete_clipable(&data.pixel->clipable);
  if (w->exit == 0)
    next_stage(win, stage, in);
  return (1);
}
