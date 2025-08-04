#include "checker.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../push_swap/push_swap.h"

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i])
        i++;
    return (s1[i] - s2[i]);
}

void error(t_stack_node **a, t_stack_node **b)
{
    free_stack(a);
    free_stack(b);
    write(2, "Error\n", 6);
    exit(1);
}

void parse_commands(t_stack_node **a, t_stack_node **b, char *command)
{
    if (!ft_strcmp(command, "pa\n"))
        pa(a, b, true);
    else if (!ft_strcmp(command, "pb\n"))
        pb(b, a, true);
    else if (!ft_strcmp(command, "sa\n"))
        sa(a, true);
    else if (!ft_strcmp(command, "sb\n"))
        sb(b, true);
    else if (!ft_strcmp(command, "ss\n"))
        ss(a, b, true);
    else if (!ft_strcmp(command, "ra\n"))
        ra(a, true);
    else if (!ft_strcmp(command, "rb\n"))
        rb(b, true);
    else if (!ft_strcmp(command, "rr\n"))
        rr(a, b, true);
    else if (!ft_strcmp(command, "rra\n"))
        rra(a, true);
    else if (!ft_strcmp(command, "rrb\n"))
        rrb(b, true);
    else if (!ft_strcmp(command, "rrr\n"))
        rrr(a, b, true);
    else
        error(a, b);
}

int main(int argc, char **argv)
{
    t_stack_node *a;
    t_stack_node *b;
    char *next_line;
    int len;
    bool flag_argc_2;

    a = NULL;
    b = NULL;
    if (argc == 1)
        return (1); // FIXED: typo "reutrn" -> "return"
    else if (argc == 2)
    {
        argv = ft_split(argv[1], ' ');
        flag_argc_2 = true;
    }
    else
        flag_argc_2 = false;

    // FIXED: Pass correct parameters to stack_init
    if (argc == 2)
        stack_init(&a, argv, flag_argc_2);
    else
        stack_init(&a, argv + 1, flag_argc_2);

    len = stack_len(a);
    next_line = get_next_line(STDIN_FILENO);
    while (next_line)
    {
        parse_commands(&a, &b, next_line);
        free(next_line); // FIXED: Free each line after processing
        next_line = get_next_line(STDIN_FILENO);
    }
    // FIXED: Remove duplicate free - next_line is already NULL here

    if (stack_sorted(a) && stack_len(a) == len && b == NULL) // FIXED: Check if b is empty
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);

    // FIXED: Proper cleanup
    free_stack(&a);
    free_stack(&b);
    if (flag_argc_2)
        free_argv(argv);

    return (0);
}