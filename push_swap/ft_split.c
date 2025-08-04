/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmezher <bmezher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 08:45:50 by bmezher           #+#    #+#             */
/*   Updated: 2025/07/30 08:50:04 by bmezher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(const char *str, char c)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

char	*sub_str(const char *str, size_t len)
{
	char		*res;
	size_t		i;

	i = 0;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(const char *str, char c)
{
	char		**result;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!result)
		return (NULL);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			while (str[j] && str[j] != c)
				j++;
			result[i] = sub_str(str, j);
			i++;
			str = str + j;
			j = 0;
		}
	}
	result[i] = NULL;
	return (result);
}
