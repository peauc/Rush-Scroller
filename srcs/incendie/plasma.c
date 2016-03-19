/*
** plasma.c for plamas in /home/peau_c/gfx_incendie
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun Dec  6 16:52:40 2015
** Last update Sat Mar 19 22:35:47 2016 Clement Peau
*/

#include "rush_plasma.h"

int	tab_setting_plasma(t_plasma *data)
{
  int	i;

  data->plasma = 0;
  i = 0;
  if ((data->tab = bunny_malloc((HEIGHT + 1) * sizeof(char *))) == NULL)
    return (0);
  while (i != HEIGHT + 1)
    if ((data->tab[i++] = bunny_malloc(WIDTH * sizeof(char))) == NULL)
      return (0);
  return (1);
}

void	 plasma(t_plasma *data)
{
  int			i;
  t_bunny_position	pos;


  i = WIDTH * HEIGHT;
  while (i != 0)
    {
      pos.x = i % WIDTH;
      pos.y = i / WIDTH;
      data->tab[i / WIDTH][i % WIDTH] =  ( 43 + (43 * sin(pos.x / 16.0))
					  + 43 + (43 * sin(pos.y / 16.0))
					  ) / data->plasma;
      tekpixel(data->pixel, pos, &data->color[(int)data->tab[i / WIDTH]
					      [i % WIDTH]], 0);
      i--;
    }
}
