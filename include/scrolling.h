/*
** scrolling.h for scrolling in /home/wery_p/rendu/gfx_scroller/include
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 19 02:37:50 2016 Paul Wery
** Last update Sat Mar 19 10:45:16 2016 Paul Wery
*/

#ifndef SCROLL
#define SCROLL

typedef struct		s_scroll
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*pix_one;
  int			start_one;
  t_bunny_pixelarray	*pix_two;
  int			start_two;
  t_bunny_pixelarray	*pix_three;
  int			start_three;
  int			state;
  t_bunny_pixelarray	*wolf;
  int			state_wolf;
  int			sprite_wolf;
  int			start_wolf;
  int			next;
}			t_scroll;

void			scrolling(t_win *w, t_stage *list, t_stage *it);
int			blit_pictures(t_scroll *s);
t_bunny_pixelarray	*resize_picture(t_bunny_pixelarray *pix,
					t_bunny_position pos);
void			moove_wolf(t_scroll *s);

#endif /* !SCROLL */
