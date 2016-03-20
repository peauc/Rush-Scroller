/*
** window.h for window in /home/wery_p/rendu/gfx_scroller/include
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Fri Mar 18 23:33:36 2016 Paul Wery
** Last update Sun Mar 20 11:20:19 2016 
*/

#ifndef WIN
#define WIN

#define WINL (1920)
#define WINH (1080)
#define RAM (100)

typedef struct		s_text
{
  t_bunny_pixelarray	*font_png;
  t_bunny_pixelarray	*back;
  t_bunny_position	start1;
  t_bunny_position	start2;
  t_bunny_position	start3;
  t_bunny_position	*end;
}			t_text;

typedef struct		s_win
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_text		*text;
}			t_win;

#endif /* !WIN */
