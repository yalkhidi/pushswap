/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 08:40:32 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/12 15:35:42 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*copy;

	copy = stack->top;
	while (copy)
	{
		printf("%ld", copy->value);
		if (copy->next != NULL)
			printf(", ");
		copy = copy->next;
	}
	printf("\n");
}



void	free_stack(t_stack *stack)
{
	if (stack->size > 0)
	{
		while (stack->size > 0)
			pop(stack);
	}
	free(stack);
}
