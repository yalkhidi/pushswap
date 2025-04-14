/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:27:49 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/12 12:34:14 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	peek_val;

	if (stack_b->size > 0)
	{
		peek_val = peek(stack_b);
		push(stack_a, peek_val);
		pop(stack_b);
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	peek_val;

	if (stack_a->size > 0)
	{
		peek_val = peek(stack_a);
		push(stack_b, peek_val);
		pop(stack_a);
	}
	write(1, "pb\n", 3);
}
