/*
** main.c for main in /home/peau_c/rendu/LibLapin/gfx_fdf1
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Sun Mar 20 18:10:31 2016 
*/

#include "demo.h"

t_bunny_response	escape_plasm(t_bunny_event_state state,
				     t_bunny_keysym key,
				     void *data)
{
  state = state;
  data = data;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

int			splited_main_plasm(t_plasma *data)
{
  data->plasma += 0.2;
  if (data->plasma > 5)
    data->plasma = 0.1;
  plasma_plasm(data);
  return (1);
}

t_bunny_response       	mainloop_plasm(void *tmp)
{
  t_plasma		*data;

  data = tmp;
  if (splited_main_plasm(data) == 0)
    return (0);
  bunny_blit(&data->window->buffer, &data->pixel->clipable, NULL);
  bunny_display(data->window);
  return (GO_ON);
}

void			plasmy_plasmy(t_win *win, t_stage *stage,
				      t_stage *actual)
{
  t_plasma		data;

  data.window = win->win;
  data.pixel = win->pix;
  fillplasma(data.pixel);
  tab_setting_plasma(&data);
  data.color = colorplasma();
  data.boole = 0;
  bunny_set_loop_main_function(mainloop_plasm);
  bunny_set_key_response(&escape_plasm);
  if (bunny_loop(data.window, 60, &data) == 0)
    return ;
  bunny_free(data.color);
  bunny_delete_clipable(&data.pixel->clipable);
  bunny_stop(data.window);
}
