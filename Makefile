# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makoch-l <makoch-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 16:46:19 by makoch-l          #+#    #+#              #
#    Updated: 2024/04/29 18:18:16 by makoch-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###

CC = gcc
CFLAGS = -Wall -Wextra -Werror

### EXECUTABLE ###

CLIENT_NAME = client
SERVER_NAME = server 

### INCLUDES ###

LIBFT_PATH = libft/
LIBFT_LIB = libft.a
LIBFT_OBJS = $(LIBFT_PATH)*.o

### SOURCE FILES ###

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

### RULES ###

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRCS) $(LIBFT_LIB)
		$(CC) $(CFLAGS) -o $@ $(CLIENT_SRCS) $(LIBFT_LIB) -lft


LIBFTMAKE = $(MAKE) -C $(LIBFT_PATH)

fclean: 

re: fclean all

.PHONY: all clean fclean re
