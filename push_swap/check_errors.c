/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmezher <bmezher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 09:42:26 by bmezher           #+#    #+#             */
/*   Updated: 2025/08/02 15:48:37 by bmezher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

checks if its not + - or a number ==> case 1

checks if the first one is + - and the next one is not a number or
it doesnt exist a number (example : +a) ==> case 2

checks in all of the string to see if its contains anything other
than numbers (example : 12a3) ==> case 3
*/

int error_syntax(char *str)
{
	int i;

	i = 1;
	if (!(str[0] == '-' || str[0] == '+' || (str[0] >= '0' && str[0] <= '9')))
		return (1);
	if ((str[0] == '-' || str[0] == '+') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

// search in the stack to see if the number exists

int error_repitition(t_stack_node *a, int nbr)
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

// freeing the mallocs

// freeing the argv
void free_argv(char **argv)
{
	int i;

	i = 0;
	if (!argv)
		return;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void free_stack(t_stack_node **stack)
{
	t_stack_node *current;
	t_stack_node *tmp;

	if (stack == NULL)
		return;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

// here we used exit instead of return: if we used exit it will exit all
// the programe but if we use return it will only exit the current function

void error_free(t_stack_node **a, char **argv, bool flag_argc_2)
{
	free_stack(a);
	if (flag_argc_2)
		free_argv(argv);
	write(2, "Error\n", 6);
	exit(1);
}