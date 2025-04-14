/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:42:51 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/10 13:51:45 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*first;	
	t_node	*temp;

	if (stack_a->size >= 2)
	{
		first = stack_a->top;
		stack_a->top = stack_a->top->next;
		temp = stack_a->top;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = first;
		first->next = NULL;
		write(1, "ra\n", 3);
	}
	else
		return ;
}

void	rb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*temp;

	if (stack_b->size >= 2)
	{
		first = stack_b->top;
		stack_b->top = stack_b->top->next;
		temp = stack_b->top;
		while (temp->next)
			temp = temp->next;
		temp->next = first;
		first->next = NULL;
		write(1, "rb\n", 3);
	}
	else
		return ;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
