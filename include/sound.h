/*
** default.h for default in /home/peau_c/bin
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Wed Feb 17 00:48:19 2016 Clement Peau
** Last update Sun Mar 20 21:11:27 2016 Poc
*/

#ifndef _SOUND_

# define _SOUND_

# include <lapin.h>
# include <stdio.h>
# include <unistd.h>

# define PUTERROR(X)	write(2, X, my_strlen(X))
# define PUTSTR(X)	write(1, X, my_strlen(X))
# define BGF		bunny_ini_get_field
# define FILE_1		"sound/darude.bsf"
# define FPS		10

typedef struct	s_pure_dope
{
  double		*duration;
  double		*freq;
  t_bunny_effect	*effect;
  int			max;
}		t_song;

t_song	*sound();
int	play_sound(t_song *);

#endif /* _SOUND_ */
