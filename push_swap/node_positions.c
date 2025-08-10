/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_positions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmezher <bmezher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 10:45:00 by bmezher           #+#    #+#             */
/*   Updated: 2025/08/09 10:45:00 by bmezher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (stack == NULL)
		return ;
	centerline = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	find_target_in_a(t_stack_node *current_b, t_stack_node *a)
{
	t_stack_node	*current_a;
	t_stack_node	*target;
	long			best_match;

	target = NULL;
	best_match = LONG_MAX;
	current_a = a;
	while (current_a)
	{
		if (current_a->value > current_b->value
			&& current_a->value < best_match)
		{
			best_match = current_a->value;
			target = current_a;
		}
		current_a = current_a->next;
	}
	if (target == NULL)
		target = find_smallest(a);
	current_b->target_node = target;
}

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;

	current_b = b;
	while (current_b)
	{
		find_target_in_a(current_b, a);
		current_b = current_b->next;
	}
}
