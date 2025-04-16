/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:14:57 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/16 18:18:01 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_chunking	*chunk;
	a = NULL;
	b = NULL;
	a = parse_a(ac, av, a);
	b = create_stack();
	if (is_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		exit(0);
	}
	// print_stack(a);
	chunk = inti_chunk(a);
	if (a->size == 3)
		sort_three(a);
	else if (a->size == 5)
		sort_five(a, b);
	else
		pushing_to_b(a, b, chunk); 
	if (is_sorted(a))
		printf("stack is sorted\n");
	else
		printf("not sorted\n");
	// printf("Stack a:\n");
	// print_stack(a);
	// printf("Stack b:\n");
	// print_stack(b);
	// int *array = copy_sort(a);
	// int j = 0;
	// while (j < a->size)
	// {
	// 	printf("%d\n", array[j]);
	// 	j++;
	// }
	// print_stack(a);
	free_stack(a);
	free_stack(b);
	free(chunk->arr);
	free(chunk);
	// free(array);
}
