/*
** get_next_line.c for get_next_line in /home/wery_p/rendu/CPE_2015_Allum1
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Wed Feb 10 22:29:28 2016 Paul Wery
** Last update Sun Mar 20 17:57:14 2016 Paul Wery
*/

#include <lapin.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "demo.h"

void	*my_realloc(char *str, int new_size)
{
  char	*line;
  int	n;

  n = 0;
  if ((line = bunny_malloc(new_size)) == NULL)
    return (NULL);
  while (n < (new_size - 1))
    {
      line[n] = str[n];
      n = n + 1;
    }
  while (n < new_size)
    {
      line[n] = '\0';
      n = n + 1;
    }
  bunny_free(str);
  return (line);
}

void	ini_line_buffer(char *line, char *buffer)
{
  line[0] = '\0';
  line[1] = '\0';
  buffer[0] = '\0';
  buffer[1] = '\0';
}

int	next_read(char *buffer, int i, int fd)
{
  int	ret;

  if ((ret = read(fd, buffer, 1)) == 0 && i == 0)
    return (-1);
  else if (ret == 0)
    buffer[0] = '\n';
  else if (ret == -1)
    return (-1);
  return (0);
}

char	*get_next_line(int fd)
{
  char	*line;
  char	*buffer;
  int	i;

  i = 0;
  if ((line = bunny_malloc(2)) == NULL)
    return (NULL);
  if ((buffer = bunny_malloc(2)) == NULL)
    return (NULL);
  ini_line_buffer(line, buffer);
  while (buffer[0] != '\n' && (buffer[0] != '\0' || i == 0))
    {
      if (next_read(buffer, i, fd) == -1)
	return (NULL);
      if (buffer[0] != '\n')
	{
	  line[i++] = buffer[0];
	  if ((line = my_realloc(line, i + 1)) == NULL)
	    return (NULL);
	}
    }
  bunny_free(buffer);
  return (line);
}
