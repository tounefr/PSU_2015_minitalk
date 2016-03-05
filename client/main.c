/*
** main.c for PSU_2015_minitalk in /home/thomas/Documents/epitech/PSU_2015_minitalk/client
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Mon Feb 01 22:07:34 2016 Thomas HENON
** Last update Sun Feb  7 23:24:42 2016 Thomas HENON
*/

#include "client.h"

void	send_signal(int pid, int sig)
{
  if (-1 == kill(pid, sig))
    {
      my_putstr("Failed to send signal\n");
      exit(1);
    }
}

void	send_char(int pid, char c)
{
  int	i;

  i = 0;
  while (i < 8)
    {
      if ((c >> i) & 1)
	send_signal(pid, SIGUSR1);
      else
	send_signal(pid, SIGUSR2);
      usleep(5000);
      i++;
    }
}

char	usage()
{
  my_putstr("Usage: ./client pid string\n");
  return (1);
}

int		main(int argc, char **argv)
{
  int		i;
  unsigned int	strLen;
  int		pid;

  if (argc != 3)
    exit(usage());
  i = 0;
  pid = my_getnbr(argv[1]);
  strLen = my_strlen(argv[2]);
  while (i < strLen)
    send_char(pid, argv[2][i++]);
  send_char(pid, 0);
  return (0);
}
