# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makoch-l <makoch-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 16:46:19 by makoch-l          #+#    #+#              #
#    Updated: 2024/04/30 00:25:19 by makoch-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

### SOURCE FILES ###

SOURCES = client.c server.c

### OBJECT FILES ###

OBJECTS = $(SOURCES:.c=.o)

### RULES ###

all: client server

client: client.o libft
		$(CC) -o $@ $< -Llibft

server: server.o libft
		$(CC) -o $@ $< -Llibft

%.o: %.c
		$(CC) -c $(CFLAGS) $?

libft:
		make -C libft

clean:
		$(RM) $(OBJECTS)
		make -C libft clean

fclean: clean
		$(RM) server client libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re
