/*
** main.c for main in /home/wery_p/rendu/gfx_scroller/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Fri Mar 18 23:31:36 2016 Paul Wery
** Last update Sun Mar 20 10:44:14 2016 
*/

#include <lapin.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "demo.h"

int	full_list(t_stage *list, t_win *w)
{
  void	(*next_stage)(t_win *, t_stage *, t_stage *);
  char	*stage;
  int	fd;

  if ((fd = open("ini_files/stages.ini", O_RDONLY)) == -1)
    {
      dprintf(2, "Cannot open ini file\n");
      return (-1);
    }
  while ((stage = get_next_line(fd)) != NULL)
    {
      if (add_elem_next(list, stage) == -1)
	return (-1);
    }
  if ((*(void **)(&next_stage) = tekfunction(list->next->stage)) == NULL)
    {
      dprintf(2, "Cannot open ini file\n");
      return (-1);
    }
  (*next_stage)(w, list, list->next);
  return (0);
}

int		main()
{
  t_win		w;
  t_stage	*list;

  bunny_set_maximum_ram(RAM * 10000000x);
  if ((w.win = bunny_start(WINL, WINH, true, "demo")) == NULL
      || (w.pix = bunny_new_pixelarray(WINL, WINH)) == NULL)
    {
      dprintf(2, "Cannot initialize windows\n");
      return (0);
    }
  if ((list = create_list()) == NULL)
    {
      dprintf(2, "Cannot create list\n");
      return (0);
    }
  if (full_list(list, &w) == -1)
    {
      dprintf(2, "Cannot initialize full list\n");
      return (0);
    }
  return (0);
}
