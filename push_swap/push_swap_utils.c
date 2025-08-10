/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmezher <bmezher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:30:00 by bmezher           #+#    #+#             */
/*   Updated: 2025/08/09 11:30:00 by bmezher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_stack_node **a, t_stack_node **b, int *len_a)
{
	while (*len_a > 3)
	{
		pb(b, a, false);
		(*len_a)--;
	}
}

static void	final_rotation(t_stack_node **a)
{
	t_stack_node	*smallest;

	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median == true)
	{
		while (*a != smallest)
			ra(a, false);
	}
	else
	{
		while (*a != smallest)
			rra(a, false);
	}
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		handle_five(a, b);
	else
		push_to_b(a, b, &len_a);
	tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	final_rotation(a);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*next_node;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}

void	free_argv(char **argv)
{
	int	index;

	if (argv == NULL)
		return ;
	index = 0;
	while (argv[index])
	{
		free(argv[index]);
		index++;
	}
	free(argv);
}
