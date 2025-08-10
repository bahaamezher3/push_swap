/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_prices.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmezher <bmezher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 10:47:00 by bmezher           #+#    #+#             */
/*   Updated: 2025/08/09 10:47:00 by bmezher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calculate_cost(t_stack_node *current_b, int len_a, int len_b)
{
	int	cost_b;
	int	cost_a;

	cost_b = current_b->current_position;
	if (current_b->above_median == false)
		cost_b = len_b - current_b->current_position;
	cost_a = current_b->target_node->current_position;
	if (current_b->target_node->above_median == false)
		cost_a = len_a - current_b->target_node->current_position;
	if (current_b->above_median == current_b->target_node->above_median)
	{
		if (cost_a > cost_b)
			current_b->push_price = cost_a;
		else
			current_b->push_price = cost_b;
	}
	else
		current_b->push_price = cost_a + cost_b;
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int				len_a;
	int				len_b;
	t_stack_node	*current_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	current_b = b;
	while (current_b)
	{
		calculate_cost(current_b, len_a, len_b);
		current_b = current_b->next;
	}
}

static void	reset_cheapest_flags(t_stack_node *b)
{
	t_stack_node	*current;

	current = b;
	while (current)
	{
		current->cheapest = false;
		current = current->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long			best_match_value;
	t_stack_node	*tmp;

	if (b == NULL)
		return ;
	reset_cheapest_flags(b);
	best_match_value = LONG_MAX;
	tmp = NULL;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			tmp = b;
		}
		b = b->next;
	}
	if (tmp != NULL)
		tmp->cheapest = true;
}
