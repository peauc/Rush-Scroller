/*
** tektext.c for tektext in /home/wery_p/rendu/gfx_tekgui/tcore
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Tue Feb 16 01:54:54 2016 Paul Wery
** Last update Sun Mar 20 16:14:39 2016 
*/

#include <lapin.h>
#include <stdio.h>
#include "demo.h"

void		draw_title_front(t_win *w,
				 t_bunny_position st,
				 int i)
{
  int			x;
  int			y;
  t_bunny_position	start;
  static int		j;
  static int		l;

  start.y = st.y - j;
  while (start.y > 0)
    {
      start.x = st.x;
      while (--start.x > i - 1)
	tekpixel_int(w->text->pix, &start, 0xff55aabb);
      start.y--;
    }
  if (l == 3)
    {
      j++;
      l = 0;
    }
  l++;
}

void		create_title(t_win *w,
			    t_bunny_position *pos,
			    int i,
			    t_bunny_position st)
{
  t_color		*color;
  t_bunny_position	start;
  int			x;
  int			y;
  int			j;

  y = -1;
  j = pos->x + (pos->y * w->text->font_png->clipable.clip_width);
  start.y = st.y;
  while (++y < 38)
    {
      x = -1;
      start.x = st.x + (i * 33);
      while (++x < 32)
        {
	  color = (t_color*)w->text->font_png->pixels + j;
	  if (check_color_font(w->text->font_png, j++) == 0)
	    tekpixel(w->text->pix, &start, color, 0);
	  start.x++;
        }
      j += (w->text->font_png->clipable.clip_width) - 32;
      start.y++;
    }
  draw_title_front(w, start, st.x + (i * 33));
}

void			title(t_win *w,
			      const char *str,
			      t_bunny_position st)
{
  int			n;
  char			*text;
  int			i;
  t_bunny_position	pos;
  char			*write;

  write = (char*)str;
  text = "abcdefghijklmnopqrstuvwxyz1234567890.,:;<-()!?+";
  i = 0;
  while (write[i] != '\0' && write)
    {
      n = 0;
      while (text[n] != write[i] && text)
	n++;
      if (n < 47)
	{
	  pos.x = n % 10 * 32;
	  pos.y = n / 10 * 39;
	  create_title(w, &pos, i, st);
	}
      i++;
    }
}
