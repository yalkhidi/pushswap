/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:03:47 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/15 17:17:26 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_valid_chars(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!(ft_isdigit(str[i][j])) &&
			str[i][j] != '-' && str[i][j] != '+' && str[i][j] != ' ')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	is_valid_token(char *str)
{
	int	i;

	i = 0;
	if ((str[0] == '+' || str[0] == '-') && str[1] == '\0')
		return (false);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '\0')
		return (false);
	else if (str[i])
	{
		while (str[i])
		{
			if ((str[i] == '+' || str[i] == '-' ) && !ft_isdigit(str[i + 1]))
				return (false);
			i++;
		}
	}
	return (true);
}

bool	check_valid_operators(int ac, char **av)
{
	int	i;

	i = ac - 1;
	while (i > 0)
	{
		if (!is_valid_token(av[i]))
			return (false);
		i--;
	}
	return (true);
}

bool	check_dup(t_stack *stack)
{
	t_node	*ptr;
	int		*array;
	int		i;
	int		j;

	i = 0;
	array = (int *)malloc(stack->size * sizeof(int));
	if (!array)
		return (NULL);
	ptr = stack->top;
	while (ptr)
	{
		j = 0;
		while (j < i)
		{
			if (array[j++] == ptr->value)
				return (free_stack(stack), free(array), false);
		}
		array[i++] = ptr->value;
		ptr = ptr->next;
	}
	free(array);
	return (false);
}
