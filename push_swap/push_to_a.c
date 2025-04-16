#include "push_swap.h"
int	get_max(t_stack *stack)
{
	t_node	*current = stack->top;
	int		max = current->value;

	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	get_max_index(t_stack *stack)
{
	t_node	*current = stack->top;
	int		max = get_max(stack);
	int		index = 0;

	while (current)
	{
		if (current->value == max)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	index;

	while (b->size > 0)
	{
		index = get_max_index(b);
		if (index <= b->size / 2)
		{
			while (index-- > 0)
				rb(b);
		}
		else
		{
			while (index++ < b->size)
				rrb(b);
		}
		pa(a, b);
	}
}
