/*
** degraded.c for degraded in
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Mar 20 16:24:24 2016 Paul Wery
** Last update Sun Mar 20 17:27:44 2016 Paul Wery
*/

#include <lapin.h>
#include "demo.h"

void		degraded_bot(t_win *w, t_bunny_position pos,
			     int ret, int state)
{
  static int	blue = 255;
  static int	green = 255;
  static int	red = 255;
  t_color	color;

  pos.y += state;
  if (blue > 10  && green <= 10)
    blue -= ret;
  if (green > 10 && red <= 10)
    green -= ret;
  if (red > 10)
    red -= ret;
  color.argb[0] = red;
  color.argb[1] = green;
  color.argb[2] = blue;
  while (pos.x < WINL)
    {
      tekpix(w->pix, &pos, &color);
      pos.x += 1;
    }
}

void		degraded_top(t_win *w, t_bunny_position pos,
			     int ret, int state)
{
  static int	blue = 255;
  static int	green = 255;
  static int	red = 255;
  t_color	color;

  pos.y -= state;
  if (blue > 10  && green <= 10)
    blue -= ret;
  if (green > 10 && red <= 10)
    green -= ret;
  if (red > 10)
    red -= ret;
  color.argb[0] = red;
  color.argb[1] = green;
  color.argb[2] = blue;
  while (pos.x < WINL)
    {
      tekpix(w->pix, &pos, &color);
      pos.x += 1;
    }
}

int			degraded(t_win *w)
{
  t_bunny_position	pos;
  static int		state = 0;

  if (state <= (WINH / 2))
    {
      pos.x = 0;
      pos.y = WINH / 2;
      degraded_top(w, pos, 2, state);
      degraded_bot(w, pos, 2, state);
      state += 1;
    }
  else
    return (1);
  return (0);
}
