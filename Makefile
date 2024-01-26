# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 12:46:17 by lpetit            #+#    #+#              #
#    Updated: 2024/01/26 10:40:28 by lpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= test

INCLUDES = -L./includes

SRCS_DIR = ./srcs/

Server_OBJS= server.o

Client_OBJS= client.o char_to_bin.o

CFLAGS = -Wall -Werror -Wextra -I./includes

.PHONY: all clean fclean re

all: server client

server: $(Server_OBJS)
		$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) -lftprintf -lft

client: $(Client_OBJS)
		$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) -lftprintf -lft

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf *.o

fclean:	clean
	rm -rf server
	rm -rf client

re:	fclean all
