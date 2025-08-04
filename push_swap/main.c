#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;
	bool flag_argc_2;

	a = NULL;
	b = NULL;
	if (argc == 1 || (2 == argc && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		flag_argc_2 = true;
		stack_init(&a, argv, flag_argc_2);
	}
	else
	{
		flag_argc_2 = false;
		stack_init(&a, argv + 1, flag_argc_2);
	}
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false); // FIXED: Added false parameter
		else if (stack_len(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}