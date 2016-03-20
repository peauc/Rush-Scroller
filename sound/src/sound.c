/*
** sound.c for sound in /home/peau_c/rendu/Lib/gfx_scroller/sound
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Sat Mar 19 17:20:44 2016 Clement Peau
** Last update Sun Mar 20 13:52:50 2016 Clement Peau
*/

#include "default.h"

int		sound()
{
  int			max;
  t_bunny_ini		*ini;
  t_song		song;
  int			i;
  t_bunny_effect	*music;

  i = 0;
  max = 0;
  if ((ini = bunny_load_ini(FILE_1)) == NULL)
    return (1);
  while (bunny_ini_get_field(ini, "track1", "duration", max) != NULL)
    max++;
  printf("max = %d\n", max);
  if ((song.duration = malloc(sizeof(double) * max)) == NULL ||
      (song.freq = malloc(sizeof(double) * max)) == NULL)
    return (1);
  while (i < max)
    {
      printf("%d\n", i);
      if (bunny_ini_get_field(ini, "track1", "duration", i) == NULL ||
	  bunny_ini_get_field(ini, "track1", "frequency", i) == NULL)
	return (write(2, "error in bsf\n", 13));
      song.duration[i] = atof(bunny_ini_get_field(ini, "track1", "duration", i));
      printf("%f\n", song.duration[i]);
      song.freq[i] = atof(bunny_ini_get_field(ini, "track1", "frequency", i));
      printf("%f\n", song.freq[i++]);
    }
  music = bunny_load_effect(bunny_ini_get_field(ini, "track1", "sample", 0));
  bunny_compute_effect(music);
  bunny_sound_play((t_bunny_sound *)music);
  i = 0;
  while (i < max)
    {
      i++;
      /* bunny_sound_stop((t_bunny_sound *)music); */
      bunny_sound_pitch((t_bunny_sound *)music, song.freq[i] / 320);
      bunny_sound_play((t_bunny_sound *)music);
      usleep(song.duration[i] * 1100);
    }
  free(song.freq);
  free(song.duration);
  exit(1);
  return (0);
}
