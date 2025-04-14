/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:26:33 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/10 13:51:49 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stack_a)
{
	t_node	*node_1;

	if (stack_a->size > 1)
	{
		node_1 = stack_a->top;
		stack_a->top = stack_a->top->next;
		node_1->next = stack_a->top->next;
		stack_a->top->next = node_1;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack	*stack_b)
{
	t_node	*node_1;

	if (stack_b->size > 1)
	{
		node_1 = stack_b->top;
		stack_b->top = stack_b->top->next;
		node_1->next = stack_b->top->next;
		stack_b->top->next = node_1;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
