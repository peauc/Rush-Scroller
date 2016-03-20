/*
** colorplasma.c for lin /home/peau_c/gfx_incendie
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Sun Dec  6 17:18:49 2015
** Last update Sun Mar 20 18:53:36 2016 Clement Peau
*/

#include "plasma.h"

void	redtoblue(int i, t_color *palet)
{
  int	r;
  int	g;

  r = 255;
  g = 0;
  while (i != 32)
    {
      palet[i].argb[0] = r - (i * 8);
      palet[i].argb[1] = g + (i * 8);
      palet[i++].argb[2] = 0;
    }
  r = 0;
  while (i != 64)
    {
      palet[i].argb[0] = 0;
      palet[i].argb[1] = g - ((i - 32) * 8);
      palet[i++].argb[2] = r + ((i - 32) * 8);
    }
  g = 0;
  while (i != 96)
    {
      palet[i].argb[0] = g + ((i - 64) * 8);
      palet[i].argb[1] = 0;
      palet[i++].argb[2] = r - ((i - 64) * 8);
    }
}

t_color	*colorplasma()
{
  int	i;
  t_color *palet;

  i = 0;
  if ((palet = bunny_malloc(96 * sizeof(t_color))) == NULL);
  redtoblue(i, palet);
  return (palet);
}
