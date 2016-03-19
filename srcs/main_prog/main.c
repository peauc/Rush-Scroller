/*
** main.c for main in /home/wery_p/rendu/gfx_scroller/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Fri Mar 18 23:31:36 2016 Paul Wery
** Last update Sat Mar 19 01:05:57 2016 Paul Wery
*/

#include <lapin.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "demo.h"

int	full_list(t_stage *list)
{
  void	(*next_stage)(void);
  char	*stage;
  int	fd;

  if ((fd = open("ini_files/stages.ini", O_RDONLY)) == -1)
    return (-1);
  while ((stage = get_next_line(fd)) != NULL)
    {
      if (add_elem_next(list, stage) == -1)
	return (-1);
    }
  if ((*(void **)(&next_stage) = tekfunction(list->next->stage)) == NULL)
    return (-1);
  (*next_stage)();
  return (0);
}

int		main()
{
  t_win		w;
  t_stage	*list;

  bunny_set_maximum_ram(RAM * 1000000);
  if ((w.win = bunny_start(WINL, WINH, false, "demo")) == NULL
      || (w.pix = bunny_new_pixelarray(WINL, WINH)) == NULL)
    return (0);
  if ((list = create_list()) == NULL)
    return (0);
  if (full_list(list) == -1)
    return (0);
  return (0);
}
