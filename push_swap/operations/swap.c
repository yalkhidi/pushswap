/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:26:33 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/15 17:13:42 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *a)
{
	t_node	*node_1;

	if (a->size > 1)
	{
		node_1 = a->top;
		a->top = a->top->next;
		node_1->next = a->top->next;
		a->top->next = node_1;
	}
	
		write(1, "sa\n", 3);
}

void	sb(t_stack	*b)
{
	t_node	*node_1;

	if (b->size > 1)
	{
		node_1 = b->top;
		b->top = b->top->next;
		node_1->next = b->top->next;
		b->top->next = node_1;
	}
	
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
