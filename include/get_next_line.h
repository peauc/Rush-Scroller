/*
** get_next_line.h for get_next_line in /home/wery_p/rendu/CPE_2015_getnextline
**
** Made by paul wery
** Login   <wery_p@epitech.net>
**
** Started on  Tue Jan  5 01:26:12 2016 paul wery
** Last update Sat Mar 19 20:13:07 2016 Clement Peau
*/

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef READ_SIZE
#  define READ_SIZE (5)

#endif /* !READ_SIZE */

typedef struct	s_line
{
  char		*line;
  int		val_ret;
  int		end;
  int		nb;
}		t_line;

#endif /* !GET_NEXT_LINE */
