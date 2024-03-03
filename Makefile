# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/03 18:15:35 by kael-ala          #+#    #+#              #
#    Updated: 2024/03/03 18:17:09 by kael-ala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CNAME = client
SNAME = server

CBNAME = client_bonus
SBNAME = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = ./ft_printf/ft_printf.c ./ft_printf/printtools.c ./ft_printf/printtoolss.c ./ft_printf/ft_atoi.c
CFILES = client.c
SFILES = server.c

CBFILES = client_bonus.c
SBFILES = server_bonus.c

OBJ = $(FILES:.c=.o)
COBJ = $(CFILES:.c=.o)
SOBJ = $(SFILES:.c=.o)

CBOBJ = $(CBFILES:.c=.o)
SBOBJ = $(SBFILES:.c=.o)

all : $(CNAME) $(SNAME)


$(CNAME) : $(OBJ) $(COBJ)
	$(CC) $^ -o $@

$(SNAME) : $(OBJ) $(SOBJ)
	$(CC) $^ -o $@

bonus : $(CBNAME) $(SBNAME)

$(CBNAME) : $(OBJ) $(CBOBJ)
	$(CC) $^ -o $@

$(SBNAME) : $(OBJ) $(SBOBJ)
	$(CC) $^ -o $@

${CBOBJ} : ./include/minitalk_bonus.h
${SBOBJ} : ./include/minitalk_bonus.h
${OBJ} : ./include/ft_printf.h 
${COBJ} :  ./include/minitalk.h 
${SOBJ} :./include/minitalk.h

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(COBJ) $(SOBJ) $(CBOBJ) $(SBOBJ)

fclean: clean
	$(RM) $(SNAME) $(CNAME) $(SBNAME) $(CBNAME)

re: fclean all

