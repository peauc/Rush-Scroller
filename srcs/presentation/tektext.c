/*
** tektext.c for tektext in /home/wery_p/rendu/gfx_tekgui/tcore
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Tue Feb 16 01:54:54 2016 Paul Wery
** Last update Sat Mar 19 20:00:50 2016 Paul Wery
*/

#include <lapin.h>
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

void		create_text(t_bunny_pixelarray *pix,
			    t_bunny_pixelarray *font_png,
			    t_bunny_position *pos UNUSED,
			    char *str,
			    int i)
{
  t_color		*color;
  t_bunny_position	start;
  int			x;
  int			y;
  int			j;

  y = -1;
  j = str[i] * 32;
  start.y = 0;
  while (++y < 38)
    {
      x = -1;
      start.x = 0 + (i * 33);
      while (++x < 32)
        {
	  color = (t_color*)font_png->pixels + x + (y * font_png->clipable.clip_width);
	  if (check_color_font(font_png, j++) == 0)
	    {
	      tekpixel(pix, &start, color, 0);
	    }
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

  write = (char*)str;
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
      create_text(out, font_png, &pos, text, n);
    }
}
