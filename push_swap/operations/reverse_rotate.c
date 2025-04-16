/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:21:43 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/15 17:12:53 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *a)
{
	t_node	*prev;
	t_node	*last;

	if (a->size >= 2)
	{
		prev = NULL;
		last = a->top;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = a->top;
		a->top = last;
		write(1, "rra\n", 4);
	}
	else
		return ;
}

void	rrb(t_stack *b)
{
	t_node	*prev;
	t_node	*last;

	if (b->size >= 2)
	{
		prev = NULL;
		last = b->top;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = b->top;
		b->top = last;
		write(1, "rrb\n", 4);
	}
	else
		return ;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
