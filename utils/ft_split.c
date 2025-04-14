/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:58:23 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/10 14:38:12 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check(char s)
{
	if (s == ' ' || s == '\t')
		return (1);
	return (0);
}

static int	words_count(char const *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] && check(s[i]))
		i++;
	while (s[i])
	{
		if (!check(s[i]))
		{
			count++;
			while (s[i] && !check(s[i]))
				i++;
		}
		while (s[i] && check(s[i]))
			i++;
	}
	return (count);
}

static char	*copy_word(char const *src, int start, int len)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = src[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s)
{
	int		i;
	int		words;
	int		a;
	char	**split;

	words = words_count(s);
	split = (char **)malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	a = 0;
	while (s[i])
	{
		while (s[i] && check(s[i]))
			i++;
		words = 0;
		while (s[i + words] && !check(s[i + words]))
			words++;
		if (words > 0)
			split[a++] = copy_word(s, i, words);
		i += words;
	}
	split[a] = NULL;
	return (split);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
