# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heolivei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 18:05:53 by heolivei          #+#    #+#              #
#    Updated: 2023/06/15 18:07:30 by heolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_S = server.c \

SRC_C = client.c \

OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
NAME = minitalk


LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ_S) $(OBJ_C)
	$(MAKE) -C ./libft
	@$(CC) $(OBJ_S) $(LIBFT) -o server
	@$(CC) $(OBJ_C) $(LIBFT) -o client

clean:
		$(MAKE) clean -C ./libft
		@$(RM) $(OBJ_S) $(OBJ_C) $(OBJ_SB) $(OBJ_CB)
fclean: clean
		@$(RM) $(LIBFT) $(NAME) server client server_bonus client_bonus
re: fclean $(NAME)
