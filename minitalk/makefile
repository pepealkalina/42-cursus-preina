# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 11:40:32 by preina-g          #+#    #+#              #
#    Updated: 2022/11/20 11:54:17 by preina-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CLIENT = client.c

SERVER = server.c

OBJCLIENT = client.o

OBJSRV = server.o

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJSRV) $(OBJCLIENT)
	@make -C libft -s
	$(CC) $(CCFLAGS) -o client $(OBJCLIENT) -L libft -lft
	$(CC) $(CCFLAGS) -o server $(OBJSRV) -L libft -lft

clean:
	@make clean -C libft
	rm -rf *.o

fclean:
	@make fclean -C libft
	rm -rf *.o server client

re: fclean all

.PHONY: all clean fclean re
