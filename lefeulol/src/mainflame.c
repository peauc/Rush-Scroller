/*
** main.c for main in /home/peau_c/rendu/LibLapin/gfx_fdf1
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Fri Mar 18 22:23:52 2016 Clement Peau
*/

#include "../include/struct.h"

t_bunny_response	escape(t_bunny_event_state state,
			       t_bunny_keysym key,
			       void *data)
{
  state = state;
  data = data;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

int			splited_main(t_data *data)
{
  first_lines(data);
  calculate(data);
  return (1);
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

int			main()
{
  t_data		data;

  data.window = bunny_start(1920, 1080, true, "test");
  data.pixel = bunny_new_pixelarray(1920, 1082);
  fill(data.pixel);
  if ((data.color = palette()) == NULL)
    return (0);
  if ((tab_setting(&data)) == 0)
    return (0);
  bunny_set_loop_main_function(mainloop);
  bunny_set_key_response(&escape);
  if (bunny_loop(data.window, 20, &data) == 0)
    return (0);
  bunny_stop(data.window);
  /* bunny_free(data.tab); */
  bunny_free(data.color);
  bunny_delete_clipable(&data.pixel->clipable);
  return (1);
}
