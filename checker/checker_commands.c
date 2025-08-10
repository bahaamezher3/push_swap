/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <username@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 00:00:00 by username          #+#    #+#             */
/*   Updated: 2024/08/09 00:00:00 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	handle_push_swap(t_stack_node **a, t_stack_node **b, char *cmd)
{
	if (!ft_strcmp(cmd, "pa\n"))
		pa(a, b, true);
	else if (!ft_strcmp(cmd, "pb\n"))
		pb(b, a, true);
	else if (!ft_strcmp(cmd, "sa\n"))
		sa(a, true);
	else if (!ft_strcmp(cmd, "sb\n"))
		sb(b, true);
	else if (!ft_strcmp(cmd, "ss\n"))
		ss(a, b, true);
	else
		handle_rotate(a, b, cmd);
}

static void	handle_rotate(t_stack_node **a, t_stack_node **b, char *cmd)
{
	if (!ft_strcmp(cmd, "ra\n"))
		ra(a, true);
	else if (!ft_strcmp(cmd, "rb\n"))
		rb(b, true);
	else if (!ft_strcmp(cmd, "rr\n"))
		rr(a, b, true);
	else if (!ft_strcmp(cmd, "rra\n"))
		rra(a, true);
	else if (!ft_strcmp(cmd, "rrb\n"))
		rrb(b, true);
	else if (!ft_strcmp(cmd, "rrr\n"))
		rrr(a, b, true);
	else
		error(a, b);
}

void	parse_commands(t_stack_node **a, t_stack_node **b, char *cmd)
{
	handle_push_swap(a, b, cmd);
}
