/*
** draw.c for draw in /home/peau_c/rendu/LibLapin/gfx_incendie
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Fri Dec  4 21:56:24 2015
** Last update Fri Mar 18 22:08:27 2016 Clement Peau
*/

#include "../include/struct.h"

int			tab_setting(t_data *data)
{
  int			i;
  int			k;

  i = 0;
  data->plasma = 0;
  if ((data->tab = bunny_malloc((HEIGHT + 2) * sizeof(char *))) == NULL)
    return (0);
  while (i <= HEIGHT + 2)
    {
      k = 0;
      if ((data->tab[i] = bunny_malloc(WIDTH * sizeof(char))) == NULL)
	return (0);
      while (k <= WIDTH - 1)
	data->tab[i][k++] = 0;
      i++;
    }
  return (1);
}

void			first_lines(t_data *data)
{
  int			i;

  i = WIDTH * (HEIGHT + 2) - 1;
  while (i > WIDTH * HEIGHT - 1)
    {
      data->tab[i / WIDTH][i % WIDTH] = rand() % 128;
      i--;

    }
}

void			calculate(t_data *data)
{
  int			i;
  t_bunny_position	pos;

  i = WIDTH * HEIGHT - 1;
  while (i > 0)
    {
      data->tab[i / WIDTH][i % WIDTH] = (data->tab[(i + WIDTH) / WIDTH]
					 [(i + 1) % WIDTH]
					 + data->tab[(i + WIDTH) / WIDTH]
					 [(i - 1) % WIDTH]
					 + data->tab[(i + 2 * WIDTH) / WIDTH]
					 [i % WIDTH]
					 + data->tab[(i - WIDTH) / WIDTH]
					 [(i + 1) % WIDTH]) / 4;
      pos.x = i % WIDTH;
      pos.y = i / WIDTH;
      tekpixel(data->pixel, pos, data->color[(int)data->tab[i / WIDTH][i % WIDTH]]);
      i--;
    }
}
