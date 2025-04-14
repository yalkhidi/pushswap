/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:28:56 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/14 18:58:11 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include "ft_printf/ft_printf.h"

//represent the node itself
typedef struct s_node
{
	long			value;
	struct s_node	*next;
}	t_node;
typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;
//represents the stack itself , 
//top is a pointer to a linked list tnode which is the top of the stack

//			Directory:root directory			//
//arg_validation.c
bool	check_valid_chars(char **str);
bool	is_valid_token(char *str);
bool	check_valid_operators(int ac, char **av);
bool	check_dup(t_stack *stack);
//input_handler.c
t_stack	*build_stack(int ac, char **av);
t_stack	*parse_stack_a(int ac, char **av, t_stack *stack_a);

//			Directory:operation			//
//push.c
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
//reverse_rotate.c
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
//rotate.c
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
//swap.c
void	sa(t_stack *stack_a);
void	sb(t_stack	*stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

//			Directory:Stack			//
//stack_ops.c
t_stack	*create_stack(void);
bool	is_empty(t_stack *stack);
void	push(t_stack *stack, long value);
void	pop(t_stack *stack);
int		peek(t_stack *stack);

//stack_utils.c
void	print_stack(t_stack *stack);
void	free_stack(t_stack *stack);

//			Directory:Utils			//
//utils.c
long	ft_atoi(char *str);
bool	ft_isdigit(char d);
bool	is_within_limits(long num);
void	print_message(char *message);
//ft_split.c
char	**ft_split(char const *s);
void	free_split(char **split);

bool	is_sorted(t_stack *stack);
void	sort_three(t_stack *stack);
int		get_min(t_stack *stack);
int		get_min_index(t_stack *stack);
void	sort_five(t_stack *a, t_stack *b);
void	sort_algo(t_stack *a, t_stack *b);
#endif