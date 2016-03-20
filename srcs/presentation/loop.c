/*
** loop.c for loop in /home/marel_m/Rendu/Semestre_2/Infographie/gfx_scroller
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Sun Mar 20 16:19:22 2016
** Last update Sun Mar 20 16:23:01 2016 
*/

#include <lapin.h>
#include "demo.h"

void			write_name(t_win *w)
{
  t_bunny_position	pos;

  tektext(w, "marel_m", w->text->start1);
  pos.x = 0;
  pos.y = 0;
  if (w->text->start1.x < WINL / 6 - 100)
    w->text->start1.x += 10;
  if (w->text->start1.y < 625)
    w->text->start1.y += 6;
  tektext(w, "peau_c", w->text->start2);
  pos.x = 0;
  pos.y = 0;
  if (w->text->start2.x < WINL / 6 - 100)
    w->text->start2.x += 10;
  if (w->text->start2.y < 725)
    w->text->start2.y += 6;
  tektext(w, "wery_p", w->text->start3);
  pos.x = 0;
  pos.y = 0;
  if (w->text->start3.x < WINL / 6 - 100)
    w->text->start3.x += 8;
  if (w->text->start3.y < 825)
    w->text->start3.y += 4;
}

void		write_title_push(t_win *w)
{
  t_bunny_position	pos;

  pos.x = WINL / 4 - 350;
  pos.y = 200;
  title(w, "rush troller", pos);
  pos.x = WINL - 500;
  pos.y = WINH - 250;
  push(w, "push the button", pos);
}
