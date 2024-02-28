# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dedsec <dedsec@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 01:03:20 by dedsec            #+#    #+#              #
#    Updated: 2024/02/27 14:20:09 by dedsec           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CNAME = client
SNAME = server

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = ./ft_printf/ft_printf.c ./ft_printf/printtools.c ./ft_printf/printtoolss.c ./ft_printf/ft_atoi.c
CFILES = client.c
SFILES = server.c

INCS = ./include/ft_printf.h ./include/minitalk.h

OBJ = $(FILES:.c=.o)
COBJ = $(CFILES:.c=.o)
SOBJ = $(SFILES:.c=.o)

all : $(CNAME) $(SNAME)

$(CNAME) : $(OBJ) $(COBJ)
	$(CC) $^ -o $@

$(SNAME) : $(OBJ) $(SOBJ)
	$(CC) $^ -o $@

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(COBJ) $(SOBJ)

fclean: clean
	$(RM) $(SNAME) $(CNAME)

re: fclean all

