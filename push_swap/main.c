/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:14:57 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/14 19:05:51 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = parse_stack_a(ac, av, stack_a);
	stack_b = create_stack();
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(0);
	}
	// print_stack(stack_a);
	sort_algo(stack_a, stack_b);
	// if (stack_a->size == 3)
	// 	sort_three(stack_a);
	// else if (stack_a->size == 5)
	// 	sort_five(stack_a, stack_b);
	// if (is_sorted(stack_a))
	// 	printf("stack is sorted\n");
	// else
	// 	printf("not sorted\n");
	// print_stack(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
}
