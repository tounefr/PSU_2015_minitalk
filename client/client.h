/*
** client.h for  in /home/thomas/Documents/epitech/PSU_2015_minitalk
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Mon Feb  1 12:18:33 2016 Thomas HENON
** Last update Mon Feb 01 23:25:39 2016 thomas
*/

#ifndef __CLIENT_H__
# define __CLIENT_H__

# include <stdlib.h>
# include <signal.h>
# include "my.h"

void	send_signal(int pid, int sig);
void	send_char(int pid, char c);
char	usage();

#endif
