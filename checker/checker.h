/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <username@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 00:00:00 by username          #+#    #+#             */
/*   Updated: 2024/08/09 00:00:00 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../push_swap/push_swap.h"

/* Function prototypes */
int		ft_strcmp(char *s1, char *s2);
void	error(t_stack_node **a, t_stack_node **b);
void	parse_commands(t_stack_node **a, t_stack_node **b, char *cmd);
void	init_stacks(int argc, char **argv, t_stack_node **a, bool *flag_argc_2);
void	process_and_check(t_stack_node **a, t_stack_node **b, int len);

/* Get next line function (assuming you have this implemented) */
char	*get_next_line(int fd);

/* Functions from push_swap project */
void	pa(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **a, t_stack_node **b, bool print);
void	sa(t_stack_node **a, bool print);
void	sb(t_stack_node **a, bool print);
void	ss(t_stack_node **a, t_stack_node **b, bool print);
void	ra(t_stack_node **a, bool print);
void	rb(t_stack_node **a, bool print);
void	rr(t_stack_node **a, t_stack_node **b, bool print);
void	rra(t_stack_node **a, bool print);
void	rrb(t_stack_node **a, bool print);
void	rrr(t_stack_node **a, t_stack_node **b, bool print);

void	stack_init(t_stack_node **a, char **argv, bool flag_argc_2);
void	free_stack(t_stack_node **stack);
void	free_argv(char **argv);
char	**ft_split(char const *s, char c);
bool	stack_sorted(t_stack_node *stack);
int		stack_len(t_stack_node *stack);

#endif