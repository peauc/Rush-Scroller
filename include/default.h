/*
** default.h for default in /home/peau_c/bin
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Wed Feb 17 00:48:19 2016 Clement Peau
** Last update Sun Mar 20 18:30:41 2016 Paul Wery
*/

#ifndef _DEFAULT_

# define _DEFAULT_

# include <lapin.h>

# define PUTERROR(X)	write(2, X, my_strlen(X))
# define PUTSTR(X)	write(1, X, my_strlen(X))

typedef struct	t_star
{
  int		y;
  float		x;
  float		x_speed;
  float		y_speed;
}		t_star;

typedef struct		s_data
{
  t_bunny_window	*window;
  t_bunny_pixelarray	*pixel;
  t_bunny_pixelarray	*star;
}			t_data;

#endif /* _DEFAULT_ */
