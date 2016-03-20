/*
** main.c for main in /home/peau_c/rendu/LibLapin/gfx_fdf1
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Thu Jan 14 02:15:10 2016 
*/

#include "struct.h"

t_bunny_response	escape(t_bunny_event_state state,
			       t_bunny_keysym key,
			       t_data *data)
{
  state = state;
  data = data;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response       	mainloop(t_data *data)
{
  fill(data->pixelarray);
  data->modifier += 1;
  cpy_pix(data->pixel, data->pixelarray, data->modifier);
  bunny_blit(&data->window->buffer, &data->pixelarray->clipable, NULL);
  bunny_display(data->window);
  return (GO_ON);
}

int			main()
{
  t_data		data;

  data.modifier = 0;
  data.window = bunny_start(1000, 1000, false, "test");
  if ((data.pixel = bunny_load_pixelarray("misc/rohan.jpg")) == NULL)
    return (0);
  if ((data.pixelarray = bunny_new_pixelarray(1000, 1000)) == NULL)
    return (0);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response((t_bunny_key)&escape);
  if (bunny_loop(data.window, 60, &data) == 0)
    return (0);
  bunny_stop(data.window);
  bunny_delete_clipable(&data.pixelarray->clipable);
  bunny_delete_clipable(&data.pixel->clipable);
  return (1);
}
