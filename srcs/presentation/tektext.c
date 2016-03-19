/*
** tektext.c for tektext in /home/wery_p/rendu/gfx_tekgui/tcore
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Tue Feb 16 01:54:54 2016 Paul Wery
** Last update Sun Feb 28 04:16:27 2016 Paul Wery
*/

#include "../include/tekgui.h"

void	actualize_pos(t_bunny_position *pos, t_bunny_position *posi,
		      unsigned int x_one, unsigned int x_two)
{
  pos[0].x = x_one;
  pos[0].y += 1;
  posi->x = x_two;
  posi->y += 1;
}

void		create_text(t_bunny_pixelarray *pix,
			    t_bunny_pixelarray *font_png,
			    t_bunny_position *pos,
			    t_bunny_position posi)
{
  t_color	*color;
  t_color	*pixel;
  int		i;
  int		n;
  unsigned int	x_one;
  unsigned int	x_two;

  x_one = pos[0].x;
  x_two = posi.x;
  while (pos[0].y < pos[1].y)
    {
      while (pos[0].x < ((int)x_one + (font_png->clipable.clip_width / 128)))
        {
          i = pos[0].x + (pos[0].y * pix->clipable.clip_width);
          n = posi.x + (posi.y * font_png->clipable.clip_width);
          color = (t_color*)pix->pixels + i;
          pixel = (t_color*)font_png->pixels + n;
	  if (pixel->argb[3] != 0)
	    color->full = pixel->full;
          pos[0].x += 1;
	  posi.x += 1;
        }
      actualize_pos(pos, &posi, x_one, x_two);
    }
}

int	strlen_or_ini(char *str, int state, t_bunny_pixelarray *pix,
		      t_bunny_position *pos)
{
  int	n;

  if (state == 1)
    {
      pos[0].x = 0;
      pos[0].y = 0;
      pos[1].x = 0;
      pos[1].y = pix->clipable.clip_height;
    }
  if (state == 2)
    {
      n = 0;
      while (str[n] != '\0')
	n += 1;
      return (n);
    }
  return (0);
}

void			tektext(t_bunny_pixelarray *out,
				const char *str,
				t_bunny_pixelarray *font_png)
{
  t_bunny_position	pos[2];
  t_bunny_position	posi;
  int			n;

  n = 0;
  posi.x = 0;
  posi.y = 0;
  strlen_or_ini((char*)str, 1, font_png, pos);
  while (n < strlen_or_ini((char*)str, 2, font_png, pos))
    {
      posi.x = str[n] * (font_png->clipable.clip_width / 128);
      if (str[n] != '\n')
	{
	  create_text(out, font_png, pos, posi);
	  pos[0].x += (font_png->clipable.clip_width / 128) + 1;
	  pos[0].y -= font_png->clipable.clip_height;
	}
      else
	{
	  pos[0].x = 0;
	  pos[0].y += font_png->clipable.clip_height + 1;
	  pos[1].y += font_png->clipable.clip_height + 1;
	}
      n += 1;
    }
}
