/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmezher <bmezher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 10:15:45 by bmezher           #+#    #+#             */
/*   Updated: 2025/08/09 10:15:45 by bmezher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_argc_2(t_stack_node **a, char **argv, bool *flag_argc_2)
{
	if (!argv[1][0])
		error_free(a, NULL, false);
	argv = ft_split(argv[1], ' ');
	*flag_argc_2 = true;
	stack_init(a, argv, *flag_argc_2);
}

static void	handle_argc_more(t_stack_node **a, char **argv, bool *flag_argc_2)
{
	*flag_argc_2 = false;
	stack_init(a, argv + 1, *flag_argc_2);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	bool			flag_argc_2;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2)
		handle_argc_2(&a, argv, &flag_argc_2);
	else
		handle_argc_more(&a, argv, &flag_argc_2);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
