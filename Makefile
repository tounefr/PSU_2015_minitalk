##
## Makefile for  in /home/thomas/Documents/epitech/PSU_2015_minitalk
## 
## Made by Thomas HENON
## Login   <thomas.henon@epitech.net>
## 
## Started on  Mon Feb  8 10:06:24 2016 Thomas HENON
## Last update Mon Feb  8 10:32:36 2016 Thomas HENON
##

CC		= gcc

RM		= rm -f

CFLAGS		= -g -I./my -lmy -L./my

NAME_CLIENT	= client

NAME_SERVER	= server

SRCS_CLIENT	= client/main.c

SRCS_SERVER	= server/main.c

OBJS_CLIENT	= $(SRCS_CLIENT:.c=.o)

OBJS_SERVER	= $(SRCS_SERVER:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) -o client/$(NAME_CLIENT) $(OBJS_CLIENT) $(CFLAGS) -I ./client

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) -o server/$(NAME_SERVER) $(OBJS_SERVER) $(CFLAGS) -I ./server

clean:
	$(RM) $(OBJS_CLIENT)
	$(RM) $(OBJS_SERVER)

fclean: clean
	$(RM) client/$(NAME_CLIENT)
	$(RM) server/$(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
