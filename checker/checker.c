/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <username@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 00:00:00 by username          #+#    #+#             */
/*   Updated: 2024/08/09 00:00:00 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

void	error(t_stack_node **a, t_stack_node **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	init_stacks(int argc, char **argv, t_stack_node **a, bool *flag_argc_2)
{
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		*flag_argc_2 = true;
		stack_init(a, argv, *flag_argc_2);
	}
	else
	{
		*flag_argc_2 = false;
		stack_init(a, argv + 1, *flag_argc_2);
	}
}

void	process_and_check(t_stack_node **a, t_stack_node **b, int len)
{
	char	*next_line;

	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		parse_commands(a, b, next_line);
		free(next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (stack_sorted(*a) && stack_len(*a) == len && *b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				len;
	bool			flag_argc_2;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	init_stacks(argc, argv, &a, &flag_argc_2);
	len = stack_len(a);
	process_and_check(&a, &b, len);
	free_stack(&a);
	free_stack(&b);
	if (flag_argc_2)
		free_argv(argv);
	return (0);
}
