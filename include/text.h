/*
** text.h for text in /home/wery_p/rendu/gfx_text/include
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Mar 19 02:37:50 2016 Paul Wery
** Last update Sat Mar 19 16:30:06 2016 
*/

#ifndef TEXT
#define TEXT

typedef struct		s_text
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*font;
}			t_text;

#endif /* !TEXT */
