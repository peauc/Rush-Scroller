/*
** demo.h for demo in /home/wery_p/rendu/gfx_scroller/include
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Fri Mar 18 23:43:43 2016 Paul Wery
** Last update Sat Mar 19 13:59:31 2016 Paul Wery
*/

#ifndef DEM
#define DEM

#define UNUSED __attribute__((unused))

typedef struct		s_stage
{
  char			*stage;
  struct s_stage	*next;
  struct s_stage	*prev;
}			t_stage;

typedef struct	stat t_stat;

char	*get_next_line(int fd);
t_stage	*create_list(void);
int	add_elem_next(t_stage *elem, char *stage);
void	delete_list(t_stage **root);
void	empty_list(t_stage *root);
void	*tekfunction(const char *funcname);
void	tekpixel(t_bunny_pixelarray *pix, t_bunny_position *pos,
		 t_color *color, int state);
void	pix_initialize(t_bunny_pixelarray *pix);

#include "window.h"
#include "scrolling.h"
#include "struct_resize.h"
#include "dam.h"

#endif /* !DEM */
