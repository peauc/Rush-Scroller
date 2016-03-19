/*
** color.c for poc in /home/peau_c/rendu/Lib/gfx_scroller/gfx_incendie
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Fri Mar 18 19:55:29 2016 Clement Peau
** Last update Fri Mar 18 21:09:13 2016 Clement Peau
*/

#include "../include/struct.h"

int		black_red(int i, t_color *col)
{
  int		r;

  r = 0;
  while (i >= 0 && i <= 31)
    {
      col[i].argb[0] = r;
      col[i].argb[1] = 0;
      col[i].argb[2] = 0;
      col[i].argb[3] = 255;
      if (i != 0)
	r = (255 / 32) * i;
      i += 1;
    }
  return (i);
}

int		red_yellow(int i, t_color *col)
{
  int		g;

  g = 0;
  while (i >= 32 && i <= 63)
    {
      col[i].argb[0] = 255;
      col[i].argb[1] = g;
      col[i].argb[2] = 0;
      col[i].argb[3] = 255;
      g = (255 / 32) * (i - 32);
      i += 1;
    }
  return (i);
}

int		yellow_white(int i, t_color *col)
{
  int		b;

  b = 0;
  while (i >= 64 && i <= 95)
    {
      col[i].argb[0] = 255;
      col[i].argb[1] = 255;
      col[i].argb[2] = b;
      col[i].argb[3] = 255;
      b = (255 / 32) * (i - 64);
      i += 1;
    }
  return (i);
}

t_color		*palette()
{
  t_color	*col;
  int		i;

  i = 0;
  if ((col = bunny_malloc(129 * sizeof(t_bunny_color))) == NULL)
    return (NULL);
  i = black_red(i, col);
  i = red_yellow(i, col);
  i = yellow_white(i, col);
  while (i != 128)
    {
      col[i].argb[0] = 255;
      col[i].argb[1] = 255;
      col[i].argb[2] = 255;
      col[i].argb[3] = 255;
      i += 1;
    }
  return (col);
}
