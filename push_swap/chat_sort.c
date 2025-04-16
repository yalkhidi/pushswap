#include "push_swap.h"

int	is_in_chunk(int value, int *sorted, int chunk_start, int chunk_end)
{
	return (value >= sorted[chunk_start] && value <= sorted[chunk_end]);
}
void	push_chunks_to_b(t_stack *a, t_stack *b, int num_chunks)
{
	int		*sorted;
	int		chunk_size;
	int		i;
	int		start, end;
	// t_node	*current;
	int		index;

	sorted = copy_sort(a);
	if (!sorted)
		return ;

	chunk_size = a->size / num_chunks;
	i = 0;
	while (i < num_chunks)
	{
		start = i * chunk_size;
		end = (i + 1) * chunk_size - 1;
		if (end >= a->size)
			end = a->size - 1;

		// Keep going until all elements from this chunk are pushed
		while (has_values_in_chunk(a, sorted, start, end))
		{
			index = find_index_in_chunk(a, sorted, start, end);
			printf("index: %d\n", index);
			print_stack(a);
			if (index <= a->size / 2)
				while (index-- > 0)
					ra(a);
			else
				while (index++ < a->size)
					rra(a);

			// If value is in upper half of the whole sorted array, do rb after pb
			if (peek(a) >= sorted[a->size / 2])
			{
				pb(a, b);
				rb(b);
			}
			else
				pb(a, b);
			print_stack(b);
		}
		i++;
	}
	free(sorted);
}
int	has_values_in_chunk(t_stack *a, int *sorted, int start, int end)
{
	t_node *current = a->top;

	while (current)
	{
		if (is_in_chunk(current->value, sorted, start, end))
			return (1);
		current = current->next;
	}
	return (0);
}
int	find_index_in_chunk(t_stack *a, int *sorted, int start, int end)
{
	t_node	*current = a->top;
	int		index = 0;

	while (current)
	{
		if (is_in_chunk(current->value, sorted, start, end))
			return (index);
		index++;
		current = current->next;
	}
	return (-1); // shouldn't happen
}
