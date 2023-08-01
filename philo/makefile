# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 13:10:34 by preina-g          #+#    #+#              #
#    Updated: 2023/07/26 15:09:21 by preina-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c parse_arg.c utils.c philo_life.c philo_life_2.c 

CC = gcc 

CFLAGS = -Wall -Wextra -Werror -g

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -pthread $(SRC) -o $(NAME)

clean:
	rm -rf *.o

fclean:
	rm -rf *.o $(NAME)

re: fclean all

.PHONY: fclean all clean re