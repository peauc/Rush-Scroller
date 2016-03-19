/*
** tektext.c for tektext in /home/wery_p/rendu/gfx_tekgui/tcore
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Tue Feb 16 01:54:54 2016 Paul Wery
** Last update Sat Mar 19 18:44:19 2016 
*/

#include <lapin.h>
#include "demo.h"

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
  printf("%d %d %d\n", r, g, b);
  if (r != 255 || b != 255 || g != 255)
    return (1);
  return (0);
}

void		create_text(t_bunny_pixelarray *pix,
			    t_bunny_pixelarray *font_png,
			    t_bunny_position *pos,
			    char *str,
			    int i)
{
  t_color		*color;
  t_bunny_position	start;
  int			x;
  int			y;
  int			n;
  int			j;

  color = (t_color*)font_png->pixels;
  y = -1;
  j = str[i] * 32;
  start.y = 1;
  while (++y < 38)
    {
      x = -1;
      start.x = 1 + (n * 33);
      while (++x < 32)
        {
	  if (check_color_font(font_png, j++) == 0)
	    tekpixel(pix, &start, color, 0);
	  start.x++;
        }
      j += (font_png->clipable.clip_width) - 32;
      start.y++;
    }
}

void			tektext(t_bunny_pixelarray *out,
				const char *str,
				t_bunny_pixelarray *font_png)
{
  int			n;
  char			*text;
  int			i;
  t_bunny_position	pos;
  char			*write;

  write = str;
  text = "abcdefghijklmnopqrstuvwxyz1234567890.,:;<-()!?+";
  i = 0;
  while (write[i] != '\0' && write)
    {
      n = 0;
      while (text[n] != write[i])
	n++;
      pos.x = n * 32 - (32 * n / 320) * 320;
      pos.y = (n * 32 / 320) * 38;
      i++;
      pos.x = 0;
      pos.y = 0;
      create_text(out, font_png, &pos, text, n);
    }
}
