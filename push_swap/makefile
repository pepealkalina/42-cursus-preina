# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 15:13:40 by preina-g          #+#    #+#              #
#    Updated: 2023/03/25 16:16:06 by preina-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libft.a

SRC = main.c parse_input.c parse_input_utils.c push_swap_main.c stacks.c set_index.c moves.c utils.c sort_three.c sort.c sort_2.c sort_utils.c target_pos.c rotate_both.c shift_stack.c

OBJ = $(SRC:.c=.o)

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft -s
	@make bonus -C libft -s
	$(CC) $(CCFLAGS) $(SRC) $(LIBFT) -o $(NAME) -g

clean:
	@make clean -C libft -s
	rm -rf *.o

fclean:
	@make fclean -C libft -s
	rm -rf *.o $(NAME)

re: fclean all

.PHONY: fclean all clean re