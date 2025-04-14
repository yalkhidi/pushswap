/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:21:43 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/10 13:51:31 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *stack_a)
{
	t_node	*prev;
	t_node	*last;

	if (stack_a->size >= 2)
	{
		prev = NULL;
		last = stack_a->top;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = stack_a->top;
		stack_a->top = last;
		write(1, "rra\n", 4);
	}
	else
		return ;
}

void	rrb(t_stack *stack_b)
{
	t_node	*prev;
	t_node	*last;

	if (stack_b->size >= 2)
	{
		prev = NULL;
		last = stack_b->top;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = stack_b->top;
		stack_b->top = last;
		write(1, "rrb\n", 4);
	}
	else
		return ;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
