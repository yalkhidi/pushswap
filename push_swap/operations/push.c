/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:27:49 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/15 17:12:20 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	peek_val;

	if (b->size > 0)
	{
		peek_val = peek(b);
		push(a, peek_val);
		pop(b);
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	int	peek_val;

	if (a->size > 0)
	{
		peek_val = peek(a);
		push(b, peek_val);
		pop(a);
	}
	
		write(1, "pb\n", 3);
}
