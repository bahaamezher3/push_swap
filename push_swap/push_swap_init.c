#include "push_swap.h"

void set_current_position(t_stack_node *stack)
{
	int i;
	int centerline;

	i = 0;
	if (stack == NULL)
		return;
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

void set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node *current_b;
	t_stack_node *current_a;
	t_stack_node *target;
	long best_match;

	current_b = b;
	while (current_b)
	{
		target = NULL;
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > current_b->value && current_a->value < best_match)
			{
				best_match = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (target == NULL)
			target = find_smallest(a);
		current_b->target_node = target;
		current_b = current_b->next;
	}
}

void set_price(t_stack_node *a, t_stack_node *b)
{
	int len_a = stack_len(a);
	int len_b = stack_len(b);

	t_stack_node *current_b = b;

	while (current_b)
	{
		int cost_b = current_b->current_position;
		if (!current_b->above_median)
			cost_b = len_b - current_b->current_position;
		int cost_a = current_b->target_node->current_position;
		if (!current_b->target_node->above_median)
			cost_a = len_a - current_b->target_node->current_position;
		if (current_b->above_median == current_b->target_node->above_median)
		{
			// Both are above or both are below median - we can rotate together
			current_b->push_price = (cost_a > cost_b) ? cost_a : cost_b;
		}
		else
		{
			// Different sides - need separate rotations
			current_b->push_price = cost_a + cost_b;
		}

		current_b = current_b->next;
	}
}
void set_cheapest(t_stack_node *b)
{
	long best_match_value;
	t_stack_node *tmp;

	if (b == NULL)
		return;
	// FIXED: Reset all cheapest flags first
	t_stack_node *current = b;
	while (current)
	{
		current->cheapest = false;
		current = current->next;
	}

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
	if (tmp) // FIXED: Check if tmp is not NULL
		tmp->cheapest = true;
}

void init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
