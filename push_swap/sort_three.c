/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:26:55 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/14 18:50:32 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_node	*nodes;

	nodes = stack->top;
	while (nodes->next)
	{
		if (nodes->value > nodes->next->value)
			return (false);
		nodes = nodes->next;
	}
	return (true);
}

void	sort_three(t_stack *stack)
{
	int	first;
	int	middle;
	int	last;

	first = peek(stack);
	middle = stack->top->next->value;
	last = stack->top->next->next->value;
	if (first > middle && middle < last && last > first)
		sa(stack);
	else if (first > middle && middle < last && last < first)
		ra(stack);
	else if (first < middle && middle > last && last < first)
		rra(stack);
	else if (first > middle && middle > last && last < first)
	{
		sa(stack);
		rra(stack);
	}
	else if (first < middle && middle > last && last > first)
	{
		sa(stack);
		ra(stack);
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min_index;

	while (a->size > 3)
	{
		min_index = get_min_index(a);
		if (min_index == 0)
			pb(a, b);
		else if (min_index <= a->size / 2)
		{
			while (min_index-- > 0)
				ra(a);
		}
		else
		{
			while (min_index++ < a->size)
				rra(a);
		}
		if (peek(a) == get_min(a) && a->size > 3)
			pb(a, b);
	}
	sort_three(a);
	if (peek(b) < b->top->next->value)
		sb(b);
	pa(a, b);
	pa(a, b);
}

int	get_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	current = stack->top;
	min = current->value;
	while (current)
	{
		if (min > current->value)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	get_min_index(t_stack *stack)
{
	int		min;
	int		min_index;
	t_node	*current;

	min = get_min(stack);
	min_index = 0;
	current = stack->top;
	while (current)
	{
		if (current->value == min)
			return (min_index);
		min_index++;
		current = current->next;
	}
	return (0);
}
