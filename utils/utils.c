/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:06:30 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/10 14:38:21 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atoi(char *str)
{
	int		i;
	long	outcome;
	int		sign;

	i = 0;
	outcome = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		else
			sign = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		outcome = outcome * 10 + (str[i] - '0');
		i++;
	}
	return (sign * outcome);
}

bool	ft_isdigit(char d)
{
	if (d >= '0' && d <= '9')
		return (true);
	return (false);
}

bool	is_within_limits(long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (false);
	return (true);
}

void	print_message(char *message)
{
	int i;

	i = 0;
	while(message[i])
		i++;
	write(2, message, i);
	exit(1);
}