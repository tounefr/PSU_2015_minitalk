/*
** main.c for PSU_2015_minitalk in /home/thomas/Documents/epitech/PSU_2015_minitalk/server
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Mon Feb 01 22:03:06 2016 Thomas HENON
** Last update Sun Feb  7 23:24:35 2016 Thomas HENON
*/

#include "server.h"

void			on_sig(int signum)
{
  static unsigned char	c;
  static int		i;

  if (signum == SIGUSR1)
    c += (1 << i);
  i++;
  if (i == 8)
    {
      if (c == 0)
	my_putchar('\n');
      else
	my_putchar(c);
      c = 0;
      i = 0;
    }
  if (signum == SIGUSR1)
    signal(SIGUSR1, on_sig);
  else if (signum == SIGUSR2)
    signal(SIGUSR2, on_sig);
  else
    exit(1);
}

int	main(int argc, char **argv)
{
  my_putstr("My PID : ");
  my_put_nbr(getpid());
  my_putchar('\n');
  signal(SIGUSR1, on_sig);
  signal(SIGUSR2, on_sig);
  while (1)
    sleep(1);
}
