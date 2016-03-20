/*
** SCRIPT
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Sun Mar 20 16:50:05 2016 Clement Peau
*/

#include "default.h"

void			movement(t_bunny_keysym key, t_data *data)
{
  key = key;
  data = data;
}

t_bunny_response	escape(t_bunny_event_state state,
			       t_bunny_keysym key,
			       t_data *data)
{
  data = data;
  state = state;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response       	mainloop(t_data *data)
{
  play_sound(data->song);
  bunny_blit(&data->window->buffer, &data->pixel->clipable, NULL);
  bunny_display(data->window);
  return (GO_ON);
}

t_song			*sound();

int			main(int ac, char **av)
{
  t_data		data;

  ac = ac;
  av = av;
  data.window = bunny_start(1000, 1000, false, "test");
  data.pixel = bunny_new_pixelarray(1000, 1000);
  if ((data.song = sound()) == NULL)
    return (0);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response((t_bunny_key)&escape);
  if (bunny_loop(data.window, 60, &data) == 0)
    return (0);
  return (1);
}
