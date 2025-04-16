/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:28:56 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/16 17:28:16 by yalkhidi         ###   ########.fr       */
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
typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;
typedef	struct s_chunking
{
	int	*arr;
	int	total_size;
	int	num_chunks;
	int	chunk_size;
	int	current_chunk;
	int	start;
	int	end;
}	t_chunking;
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
t_stack	*parse_a(int ac, char **av, t_stack *a);

//			Directory:operation			//
//push.c
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
//reverse_rotate.c
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
//rotate.c
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
//swap.c
void	sa(t_stack *a);
void	sb(t_stack	*b);
void	ss(t_stack *a, t_stack *b);

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
int		*copy_sort(t_stack *a);
void	ft_sort_int_tab(int	*tab, int size);
// void	push_chunks_to_b(t_stack *a, t_stack *b, int num_chunks);
// int	has_values_in_chunk(t_stack *a, int *sorted, int start, int end);
// int	find_index_in_chunk(t_stack *a, int *sorted, int start, int end);
// int	is_in_chunk(int value, int *sorted, int chunk_start, int chunk_end);
t_chunking	*inti_chunk(t_stack *a);
void	pushing_to_b(t_stack *a, t_stack *b, t_chunking *chunking);
bool    is_in_chunk(t_chunking *chunk, int value);
bool    has_value_in_chunk(t_stack *a, t_chunking *chunk);
int value_index(t_stack *a, t_chunking *chunk);
int	chunk_count(int stack_size);
int	get_max(t_stack *stack);
int	get_max_index(t_stack *stack);
void	push_back_to_a(t_stack *a, t_stack *b);
int	get_closest_in_chunk(t_stack *a, t_chunking *chunk);
#endif