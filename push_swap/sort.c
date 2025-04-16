/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:51:49 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/16 17:32:50 by yalkhidi         ###   ########.fr       */
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

int	*copy_sort(t_stack *a)
{
	int		*array;
	t_node	*current;
	int		i;

	array = (int *)malloc(sizeof(int) * a->size);
	if (!array)
		return (NULL);
	current = a->top;
	i = 0;
	while (current)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}
	ft_sort_int_tab(array, a->size);
	return (array);
}

void	ft_sort_int_tab(int	*tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i +1;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	chunk_count(int size)
{
	if (size <= 10)
		return 1;
	if (size <= 100)
		return 10;
	if (size <= 200)
		return 20;
	if (size <= 300)
		return 25;
	if (size <= 400)
		return 30;
	return 35; // for 500 or more
}


// t_chunking	*inti_chunk(t_stack *a)
// {
// 	t_chunking *info;

// 	info = (t_chunking *)malloc(sizeof(t_chunking));
// 	info->arr = copy_sort(a);
// 	info->total_size = a->size;
// 	info->num_chunks = chunk_count(a->size);
// 	info->chunk_size = info->total_size / info->num_chunks;
// 	info->current_chunk = 0;
// }
// void	pushing_to_b(t_stack *a, t_stack *b, t_chunking *chunking)
// {
// 	t_node	*current;
// 	int		i;

// 	current = a->top;
// 	i = 0;
// 	while (chunking->num_chunks)
// 	{
// 		chunking->start = i * chunking->chunk_size;
// 		chunking->end = (i + 1) * (chunking->chunk_size - 1);
// 		if (chunking->end >= a->size)
// 			chunking->end = a->size - 1;
		
// 	}
// }
