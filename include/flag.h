/*
** struct.h for struct in /home/peau_c/rendu/LibLapin/gfx_fdf1
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:23:46 2015 clement peau
** Last update Sun Mar 20 19:58:58 2016 Poc
*/

#ifndef MY_STRUCT
# define MY_STRUCT

# define DEST_HEIGHT dest->clipable.clip_height
# define DEST_WIDTH dest->clipable.clip_width
# define SRC_HEIGHT src->clipable.clip_height
# define SRC_WIDTH src->clipable.clip_width
# define FLAG_WIDTH data->pixel->clipable.clip_width
# define FLAG_HEIGHT data->pixel->clipable.clip_height

# include <unistd.h>
# include "lapin.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct		s_flag
{
  t_bunny_pixelarray	*pixel;
  t_bunny_window	*window;
  t_bunny_pixelarray	*pixelarray;
  double		modifier;
}			t_flag;

void			cpy_pix(t_bunny_pixelarray *, t_bunny_pixelarray *,
				double);
void			fill_flag(t_bunny_pixelarray *);
void			prepare(t_bunny_pixelarray *);

#endif	/* MY_STRUCT  */
