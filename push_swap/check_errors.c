/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmezher <bmezher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 09:42:26 by bmezher           #+#    #+#             */
/*   Updated: 2025/08/09 10:05:14 by bmezher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str)
{
	int	i;

	i = 1;
	if (!(str[0] == '-' || str[0] == '+'
			|| (str[0] >= '0' && str[0] <= '9')))
		return (1);
	if ((str[0] == '-' || str[0] == '+')
		&& !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	error_repitition(t_stack_node *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_all(char **argv, t_stack_node **stack, bool free_argv_flag)
{
	t_stack_node	*cur;
	t_stack_node	*tmp;
	int				i;

	if (free_argv_flag && argv)
	{
		i = 0;
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
	if (stack && *stack)
	{
		cur = *stack;
		while (cur)
		{
			tmp = cur->next;
			free(cur);
			cur = tmp;
		}
		*stack = NULL;
	}
}

void	error_free(t_stack_node **a, char **argv, bool flag_argc_2)
{
	free_all(argv, a, flag_argc_2);
	write(2, "Error\n", 6);
	exit(1);
}
