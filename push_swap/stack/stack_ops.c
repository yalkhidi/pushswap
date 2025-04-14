/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:07:41 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/12 14:41:03 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

bool	is_empty(t_stack *stack)
{
	if (stack->top == NULL)
		return (true);
	else
		return (false);
}

void	push(t_stack *stack, long value)
{
	t_node	*new_node;

	if (!stack)
		return ;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

void	pop(t_stack *stack)
{
	t_node	*node;

	if (is_empty(stack))
		return ;
	node = stack->top;
	stack->top = stack->top->next;
	free(node);
	stack->size--;
}

int	peek(t_stack *stack)
{
	if (is_empty(stack))
		return (-1);
	return (stack->top->value);
}
