# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thessena <thessena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 10:55:15 by thessena          #+#    #+#              #
#    Updated: 2024/12/11 15:50:54 by thessena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = src/server.c src/utils.c
SRC_CLIENT = src/client.c src/utils.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SRC_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SRC_SERVER)

$(NAME_CLIENT): $(SRC_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(SRC_CLIENT)

clean:
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: clean all
