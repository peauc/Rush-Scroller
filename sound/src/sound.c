/*
** sound.c for sound in /home/peau_c/rendu/Lib/gfx_scroller/sound
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Sat Mar 19 17:20:44 2016 Clement Peau
** Last update Sun Mar 20 21:05:03 2016 Poc
*/

#include "sound.h"

int		play_sound(t_song *song)
{
  static float		i = 0;
  static int		inc = 0;

  if (i / FPS >= song->duration[inc] / 1000)
    {
      bunny_sound_play((t_bunny_sound *)song->effect);
      bunny_sound_pitch((t_bunny_sound *)song->effect,
			song->freq[(int)inc] / 100);
      bunny_sound_play((t_bunny_sound *)song->effect);
      i = 0;
      if (++inc == song->max)
	inc = 0;
    }
  i++;
  return (0);
}

int		sound_continued(t_song *song, t_bunny_ini *ini, int i)
{
  if (BGF(ini, "track1", "duration", i) == NULL ||
      BGF(ini, "track1", "frequency", i) == NULL ||
      BGF(ini, "track1", "sample", 0) == NULL)
    return (0);
  song->duration[i] = atof(BGF(ini, "track1", "duration", i));
  song->freq[i] = atof(BGF(ini, "track1", "frequency", i));
  return (1);
}

t_song		*sound()
{
  int			max;
  t_bunny_ini		*ini;
  t_song		*song;
  int			i;

  i = 0;
  max = 0;
  if ((ini = bunny_load_ini(FILE_1)) == NULL)
    return (NULL);
  while (BGF(ini, "track1", "duration", max) != NULL)
    max++;
  if (((song = bunny_malloc(sizeof(t_song))) == NULL) ||
      ((song->duration = bunny_malloc(sizeof(double) * (max + 1))) == NULL) ||
      ((song->freq = bunny_malloc(sizeof(double) * (max + 1))) == NULL))
    return (NULL);
  while (i < max)
      sound_continued(song, ini, i++);
  if (bunny_load_effect(BGF(ini, "track1", "sample", 0)) == NULL)
    return (NULL);
  song->effect = bunny_load_effect(BGF(ini, "track1", "sample", 0));
  song->max = max;
  return (song);
}
