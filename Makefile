# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 12:46:17 by lpetit            #+#    #+#              #
#    Updated: 2024/02/09 14:15:12 by lpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -L./includes

SERVER_OBJS= server.o

CLIENT_OBJS= client.o char_to_bin.o

CFLAGS = -Wall -Werror -Wextra -I./includes

.PHONY: all clean fclean re

all: server client

server: $(SERVER_OBJS)
		$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) -lftprintf -lft

client: $(CLIENT_OBJS)
		$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) -lftprintf -lft

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(SERVER_OBJS)
	rm -rf $(CLIENT_OBJS)

fclean:	clean
	rm -rf server
	rm -rf client

re:	fclean all
