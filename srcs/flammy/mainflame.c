/*
** main.c for main in /home/peau_c/rendu/LibLapin/gfx_fdf1
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Sun Mar 20 19:53:39 2016 Poc
*/

#include "demo.h"

t_bunny_response	escape(t_bunny_event_state state,
			       t_bunny_keysym key,
			       void *data)
{
  t_flame		*flame;

  flame = (t_flame*)data;
  if (state == GO_UP && key == BKS_ESCAPE)
    {
      flame->exit = 1;
      return (EXIT_ON_SUCCESS);
    }
  else if  (state == GO_UP && key == BKS_RETURN)
    return (EXIT_ON_SUCCESS);
  else if (state == GO_UP && key == BKS_SPACE)
    {
      if (flame->state == 0)
	flame->state = 1;
      else
	flame->state = 0;
    }
  return (GO_ON);
}

int	splited_main(t_flame *data)
{
  first_lines(data);
  calculate(data);
  draw_scroll(data);
  return (1);
}

t_bunny_response	mainloop(void *tmp)
{
  t_flame		*data;

  data = tmp;
  if (splited_main(data) == 0)
    return (0);
  if (data->state == 0)
    starfield(data->pixel, data->star, 500);
  else
    frontal_stars(data->pixel, data->star, 500);
  bunny_blit(&data->window->buffer, &data->pixel->clipable, NULL);
  bunny_display(data->window);
  return (GO_ON);
}

void		flamy_flamy(t_win *win, t_stage *stage, t_stage *actual)
{
  t_flame	data;

  data.exit = 0;
  data.state = 0;
  data.window = win->win;
  if ((data.pixel = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return ;
  if ((data.star = init_starfield(data.pixel, 500)) == NULL)
    return ;
  fill(data.pixel);
  if ((data.color = palette()) == NULL)
    return ;
  if ((tab_setting(&data)) == 0)
    return ;
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response(&escape);
  if (bunny_loop(data.window, 20, &data) == 0)
    return ;
  bunny_free(data.color);
  bunny_delete_clipable(&data.pixel->clipable);
  if (data.exit == 0)
    next_stage(win, stage, actual);
}
