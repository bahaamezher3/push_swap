/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmezher <bmezher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:21:35 by bmezher           #+#    #+#             */
/*   Updated: 2025/08/09 11:20:00 by bmezher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_rotation(t_stack_node **stack,
	t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median == true)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median == true)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	rotate_both(t_stack_node **a,
	t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

void	reverse_rotate_both(t_stack_node **a,
	t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median == true
		&& cheapest_node->target_node->above_median == true)
		rotate_both(a, b, cheapest_node);
	else if (cheapest_node->above_median == false
		&& cheapest_node->target_node->above_median == false)
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b, false);
}
