/*
** demo.h for demo in /home/wery_p/rendu/gfx_scroller/include
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Fri Mar 18 23:43:43 2016 Paul Wery
** Last update Sun Mar 20 19:08:38 2016 Clement Peau
*/

#ifndef DEM
#define DEM

#define UNUSED __attribute__((unused))

typedef struct	stat t_stat;
typedef struct		s_stage
{
  char			*stage;
  struct s_stage	*next;
  struct s_stage	*prev;
}			t_stage;

#include <lapin.h>
#include "plasmy.h"
#include "window.h"
#include "scrolling.h"
#include "struct_resize.h"
#include "dam.h"

# ifndef MY_STRUCT
#  include "flammy.h"
# endif
char	*get_next_line(int fd);
t_stage	*create_list(void);
int	add_elem_next(t_stage *elem, char *stage);
void	delete_list(t_stage **root);
void	empty_list(t_stage *root);
void	*tekfunction(const char *funcname);
void	tekpixel(t_bunny_pixelarray *, t_bunny_position *pos,
		 t_color *color, int state);
void	pix_initialize(t_bunny_pixelarray *pix);
void	pix_initialize_txt(t_bunny_pixelarray *);
void	put_pix_in_pix_txt(t_bunny_pixelarray *, t_bunny_pixelarray *, t_bunny_position);
void	tektext(t_win *, const char *, t_bunny_position);
void	write_name(t_win *);
void	write_title_push(t_win *);
void	push(t_win *, const char *, t_bunny_position);
void    next_stage(t_win *w, t_stage *list, t_stage *it);
void	deg(t_win *w, t_stage *list, t_stage *it);
int	degraded(t_win *w);
void	tekpix(t_bunny_pixelarray *pix,
	       t_bunny_position *pos,
	       t_color *color);

#endif /* !DEM */
