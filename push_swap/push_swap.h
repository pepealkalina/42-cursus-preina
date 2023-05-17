/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.f    		+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:37:33 by preina-g          #+#    #+#             */
/*   Updated: 2023/03/25 11:06:11 by preina-g      	  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "stdio.h"

//listas

typedef struct s_stack
{
	int				value;
	int				pos;
	int				index;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}t_stack;

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}t_bool;

typedef struct s_data
{
	int				lst_len;
	int				split_len;
	char			**split_argu;
	int				*num_list;
	t_stack			*stack_a;
	t_stack			*stack_b;
}t_data;

int		ft_is_num(char **argv);
int		ft_check_input(char **argv, int argc, t_data *data, int flag);
int		*ft_atoi_input(char **argv, int argc);
int		ft_check_dup(char **argv, int argc, t_data *data);
void	ft_split_argv(char *argv, t_data *data);
int		push_swap_main(t_data *data);
t_stack	*ft_fill_stack(t_data *data, t_stack *stack);
void	ft_set_index(t_stack *stack);
t_stack	*ft_last_node(t_stack *stack);
t_stack	*ft_before_last_node(t_stack *stack);
void	rotate(t_stack **stack);
void	swap(t_stack *stack);
void	reverse_rotate(t_stack **stack);
void	push(t_stack **stack_a, t_stack **stack_b);
int		ft_sort_three(t_stack **stack, t_stack **b);
void	ft_reset_pos(t_stack *stack);
int		ft_stack_size(t_stack *stack);
void	ft_sort(t_stack **a, t_stack **b);
void	ft_target_pos(t_stack *a, t_stack *b);
void	ft_cost(t_stack **a, t_stack **b);
void	ft_push_and_rotate(t_stack **a, t_stack **b, int cost_b, int cost_a);
long	ft_abs(int n);
void	ft_move(t_stack **a, t_stack **b);
void	ft_ra(t_stack **a, int cost_a);
void	ft_rb(t_stack **b, int cost_b);
void	ft_rr_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void	ft_rrr_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_shift_stack(t_stack **a);
void	ft_free_list(t_stack **lst);
int		ft_ordered(t_stack *a);
int		ft_lower_pos(t_stack *s);

#endif