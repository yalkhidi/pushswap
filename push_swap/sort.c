/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:51:49 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/14 18:59:55 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_algo(t_stack *a, t_stack *b)
{
	int	min_in;

	while (a->size > 0)
	{
		min_in = get_min_index(a);
		if (min_in <= a->size / 2)
		{
			while (min_in)
			{
				ra(a);
				min_in--;
			}
		}
		else
		{
			while (min_in < a->size)
			{
				rra(a);
				min_in++;
			}
		}
		pb(a, b);
	}
	while (b->size)
		pa(a, b);
}
