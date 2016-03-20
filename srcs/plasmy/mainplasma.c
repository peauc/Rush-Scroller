/*
** main.c for main in /home/peau_c/rendu/LibLapin/gfx_fdf1
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Sun Mar 20 19:54:37 2016 Poc
*/

#include "plasma.h"

t_bunny_response	escape_plasma(t_bunny_event_state state,
			       t_bunny_keysym key,
			       t_data *data)
{
  state = state;
  data = data;
  if (key == BKS_ESCAPE)
    {
      data->win_struct->exit = 1;
      return (EXIT_ON_SUCCESS);
    }
  if (key == BKS_RETURN)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

int			splited_main_plasma(t_data *data)
{
  data->plasma += 0.2;
  if (data->plasma > 5)
    data->plasma = 0.1;
  plasma(data);
  return (1);
}

t_bunny_response       	mainloop_plasma(t_data *data)
{
  if (splited_main_plasma(data) == 0)
    return (0);
  bunny_blit(&data->win_struct->win->buffer, &data->pixel->clipable, NULL);
  bunny_display(data->win_struct->win);
  return (GO_ON);
}

int			plasmy_plasmy(t_win *win, t_stage *stage, t_stage *in)
{
  t_data		data;

  data.win_struct = win;
  data.win_struct->exit = 0;
  data.pixel = bunny_new_pixelarray(1920, 1080);
  fillplasma(data.pixel);
  tab_setting_plasma(&data);
  data.color = colorplasma();
  data.boole = 0;
  bunny_set_loop_main_function((t_bunny_loop)&mainloop_plasma);
  bunny_set_key_response((t_bunny_key)&escape_plasma);
  if (bunny_loop(data.win_struct->win, 20, &data) == 0)
    return (0);
  bunny_free(data.color);
  bunny_delete_clipable(&data.pixel->clipable);
  if (data.win_struct->exit == 0)
    next_stage(win, stage, in);
  return (1);
}
