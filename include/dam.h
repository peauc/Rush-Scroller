/*
** dam.h for dam in /home/wery_p/rendu/gfx_scroller/include
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 19 13:50:57 2016 Paul Wery
** Last update Sat Mar 19 14:06:06 2016 Paul Wery
*/

#ifndef DAM
#define DAM

typedef struct		s_dam
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*filter;
}			t_dam;

void	dam(t_dam *d);

#endif /* !DAM */
