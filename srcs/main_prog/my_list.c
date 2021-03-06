/*
** my_list.c for my_list in /home/wery_p/rendu/gfx_scroller/srcs/main_prog
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Fri Mar 18 23:41:57 2016 Paul Wery
** Last update Sun Mar 20 17:54:31 2016 Paul Wery
*/

#include <lapin.h>
#include <stdlib.h>
#include <unistd.h>
#include "demo.h"

void		empty_list(t_stage *root)
{
  t_stage	*it;
  t_stage	*save;

  it = root->next;
  while (it != root)
    {
      save = it->next;
      bunny_free(it->stage);
      bunny_free(it);
      it = save;
    }
}

void	delete_list(t_stage **root)
{
  empty_list(*root);
  bunny_free(*root);
  *root = NULL;
}

int		add_elem_next(t_stage *elem, char *stage)
{
  t_stage	*new_elem;

  if ((new_elem = bunny_malloc(sizeof(*new_elem))) == NULL)
    return (-1);
  new_elem->stage = stage;
  new_elem->next = elem;
  new_elem->prev = elem->prev;
  elem->prev->next = new_elem;
  elem->prev = new_elem;
  return (0);
}

t_stage		*create_list(void)
{
  t_stage	*root;

  if ((root = bunny_malloc(sizeof(*root))) == NULL)
    return (NULL);
  root->prev = root;
  root->next = root;
  return (root);
}
