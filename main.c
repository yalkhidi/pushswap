/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:14:57 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/12 14:49:49 by yalkhidi         ###   ########.fr       */
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
	// sort_three(stack_a);

	mechanical_turk(stack_a, stack_b);
	// print_stack(stack_a);
	if(is_sorted(stack_a))
		printf("stack is sorted\n");
	else
		printf("not sorted\n");
	// print_stack(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
}
