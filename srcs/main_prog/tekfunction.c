/*
** tekfunction.c for tekfunction in /home/wery_p/rendu/gfx_tekgui/tcore
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sat Feb 13 21:20:32 2016 Paul Wery
** Last update Sat Feb 27 18:53:19 2016 Paul Wery
*/

#include <lapin.h>
#include <dlfcn.h>

void	*tekfunction(const char *funcname)
{
  void	*handle;
  void	*fonc;

  handle = NULL;
  fonc = NULL;
  if ((handle = dlopen(NULL, RTLD_LAZY)) != NULL)
      fonc = dlsym(handle, funcname);
  return (fonc);
}
