# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 13:10:34 by preina-g          #+#    #+#              #
#    Updated: 2023/07/05 08:44:43 by preina-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c parse_arg.c utils.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) -pthread $(SRC) -o $(NAME) -g

clean:
	rm -rf *.o

fclean:
	rm -rf *.o $(NAME)

re: fclean all

.PHONY: fclean all clean re