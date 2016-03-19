/*
** dam.h for dam in /home/wery_p/rendu/gfx_scroller/include
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 19 13:50:57 2016 Paul Wery
** Last update Sat Mar 19 18:33:12 2016 Paul Wery
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
void	dam_two(t_dam *d);
void	reverse_color(t_color *color);

#endif /* !DAM */
