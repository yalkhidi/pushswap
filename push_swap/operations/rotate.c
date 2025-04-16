/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:42:51 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/15 17:13:14 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *a)
{
	t_node	*first;	
	t_node	*temp;

	if (a->size >= 2)
	{
		first = a->top;
		a->top = a->top->next;
		temp = a->top;
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

void	rb(t_stack *b)
{
	t_node	*first;
	t_node	*temp;

	if (b->size >= 2)
	{
		first = b->top;
		b->top = b->top->next;
		temp = b->top;
		while (temp->next)
			temp = temp->next;
		temp->next = first;
		first->next = NULL;
		write(1, "rb\n", 3);
	}
	else
		return ;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
