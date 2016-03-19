/*
** struct_resize.h for struct_resize in /home/wery_p/rendu/flip_part_2020
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Feb 22 14:38:59 2016 Paul Wery
** Last update Thu Feb 25 17:46:43 2016 Paul Wery
*/

#ifndef RZ
#define RZ

typedef struct	s_my_scale
{
  double	scale_x;
  double	scale_y;
}		t_my_scale;

typedef struct	s_resize
{
  double	x_one;
  double	y_one;
  double	x_two;
  double	y_two;
  t_color	*color;
  t_color	*pixel;
  int		i;
}		t_resize;

#endif /* RZ */
