/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmezher <bmezher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 08:03:46 by bmezher           #+#    #+#             */
/*   Updated: 2025/08/09 11:05:00 by bmezher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

char			**ft_split(const char *str, char c);
void			stack_init(t_stack_node **a, char **argv, bool flag_argc_2);
int				error_repitition(t_stack_node *a, int nbr);
int				error_syntax(char *str);
void			append_node(t_stack_node **stack, int nbr);
void			error_free(t_stack_node **a, char **argv, bool flag_argc_2);
t_stack_node	*find_last_node(t_stack_node *head);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
void			finish_rotation(t_stack_node **s, t_stack_node *n, char c);

void			sa(t_stack_node **a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);
void			pa(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **b, t_stack_node **a, bool checker);

void			init_nodes(t_stack_node *a, t_stack_node *b);
void			handle_five(t_stack_node **a, t_stack_node **b);
void			tiny_sort(t_stack_node **a);
void			set_current_position(t_stack_node *stack);
void			set_target_node(t_stack_node *a, t_stack_node *b);
void			set_price(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);
void			push_swap(t_stack_node **a, t_stack_node **b);
void			free_stack(t_stack_node **stack);
void			free_argv(char **argv);
void			move_nodes(t_stack_node **a, t_stack_node **b);

#endif