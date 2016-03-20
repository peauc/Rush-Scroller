/*
** struct.h for struct in /home/peau_c/rendu/LibLapin/gfx_fdf1
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:23:46 2015 clement peau
** Last update Sun Mar 20 18:43:47 2016 Paul Wery
*/

#ifndef MY_FLAMMY
# define MY_FLAMMY

# include <unistd.h>
# include <lapin.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <demo.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct	t_star
{
  int		y;
  float		x;
  float		x_speed;
  float		y_speed;
}		t_star;

typedef struct		s_flame
{
  t_bunny_pixelarray	*pixel;
  t_star		*star;
  t_color		*color;
  t_bunny_window	*window;
  t_bunny_ini		*ini;
  t_bunny_position	pos;
  char			**tab;
  float			plasma;
  int			boole;
  int			exit;
  int			state;
}			t_flame;

t_bunny_response	escape(t_bunny_event_state, t_bunny_keysym, void *);
int			splited_main(t_flame *);
t_bunny_response	mainloop(void *);
int			second_line(t_flame *, int, unsigned int *);
t_color *		palette();
void			tekpixelplasma(t_bunny_pixelarray *, t_bunny_position,
				       t_color);
void			first_lines(t_flame *);
void			fillplasma(t_bunny_pixelarray *);
void			calculate(t_flame *);
t_color			*colorplasma();
void			fill(t_bunny_pixelarray *);
void			prepare(t_bunny_pixelarray *);
int			tab_setting(t_flame *);
void			plasma(t_flame *);
void			frontal_stars(t_bunny_pixelarray *,
				      t_star *, int);
t_star			*init_starfield(t_bunny_pixelarray *,
					int);
void			starfield(t_bunny_pixelarray *, t_star *, int);

#endif	/* MY_FLAMMy  */
