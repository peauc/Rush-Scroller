/*
** tektext.c for tektext in /home/wery_p/rendu/gfx_tekgui/tcore
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Tue Feb 16 01:54:54 2016 Paul Wery
** Last update Sun Mar 20 14:18:45 2016 
*/

#include <lapin.h>
#include <stdio.h>
#include "demo.h"

void		pix_initialize_txt(t_bunny_pixelarray *pix)
{
  t_color	*color;
  int		n;
  int		i;

  n = 0;
  i = pix->clipable.clip_width * pix->clipable.clip_height;
  while (n < i)
    {
      color = (t_color*)pix->pixels + n;
      color->full = 0x00000000;
      n++;
    }
}

void                    put_pix_in_pix_txt(t_bunny_pixelarray *pix,
					   t_bunny_pixelarray *src,
					   t_bunny_position pos)
{
  t_bunny_position      posi;
  t_color               *color;
  int                   i;

  posi.y = 0;
  while (pos.y < WINH && posi.y < src->clipable.clip_height)
    {
      pos.x = 0;
      posi.x = 0;
      while (pos.x < WINL)
	{
	  i = posi.x + (posi.y * src->clipable.clip_width);
	  color = (t_color*)src->pixels + i;
	  if (color->argb[3] != 0)
	    tekpixel(pix, &pos, color, 0);
	  pos.x++;
	  posi.x++;
	}
      pos.y++;
      posi.y++;
    }
}

int     check_color_font(t_bunny_pixelarray *font_png,
			 int i)
{
  int           r;
  int           b;
  int           g;
  t_color       *color;

  color = (t_color*)font_png->pixels;
  r = color[i].full & 0xFF;
  g = (color[i].full >> 8) & 0xFF;
  b = (color[i].full >> 16) & 0xFF;
  if (r == 255 && b == 255 && g == 255)
    return (1);
  return (0);
}

void		create_text(t_win *w,
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
  start.y = st.y + (i * 7);
  while (++y < 38)
    {
      x = -1;
      start.x = st.x + (i * 33);
      while (++x < 32)
        {
	  color = (t_color*)w->text->font_png->pixels + j;
	  if (check_color_font(w->text->font_png, j++) == 0)
	    tekpixel(w->pix, &start, color, 0);
	  start.x++;
        }
      j += (w->text->font_png->clipable.clip_width) - 32;
      start.y +=  2;
    }
}

void			tektext(t_win *w,
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
	  create_text(w, &pos, i, st);
	}
      i++;
    }
}
