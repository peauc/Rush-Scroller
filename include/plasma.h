/*
** struct.h for struct in /home/peau_c/rendu/LibLapin/gfx_fdf1
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:23:46 2015 clement peau
** Last update Sun Mar 20 19:32:23 2016 Poc
*/

#ifndef PLASMA
# define PLASMA

# include <unistd.h>
# include <lapin.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "demo.h"
# include "window.h"

#define WIDTH	WINL
#define HEIGHT	WINH

typedef struct		s_data
{
  t_win			*win_struct;
  t_bunny_pixelarray	*pixel;
  t_color		*color;
  t_bunny_window	*window;
  t_bunny_ini		*ini;
  t_bunny_position	pos;
  char			**tab;
  float			plasma;
  int			boole;
}			t_data;

t_bunny_response escape(t_bunny_event_state, t_bunny_keysym, t_data *);
int splited_main(t_data *);
t_bunny_response mainloop(t_data *);
int second_line(t_data *, int, unsigned int *);
t_color *palette();
void tekpixelplasma(t_bunny_pixelarray *, t_bunny_position, t_color);
void first_lines(t_data *);
void fillplasma(t_bunny_pixelarray *);
void calculate(t_data *);
t_color *colorplasma();
void fill(t_bunny_pixelarray *);
void prepare(t_bunny_pixelarray *);
int tab_setting_plasma(t_data *);
void plasma(t_data *);
#endif	/* PLASMA  */
