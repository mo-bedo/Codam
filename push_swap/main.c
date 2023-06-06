#include "push_swap.h"

static void	sort_twentysix(t_list **stack_a, t_list **stack_b)
{
	while (1)
	{
		if (is_smallest(*stack_a))
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
		if (!(*stack_a))
		{
			while (*stack_b)
				push_a(stack_a, stack_b);
		}
		if (!(*stack_b))
			is_sorted_check(*stack_a);
	}
}

static void	sort_by_argc(t_list *stack_a, int argc)
{
	t_list	*stack_b;
	int		max_order;

	stack_b = NULL;
	error_check(stack_a, NULL);
	is_sorted_check(stack_a);
	if (argc == 3)
	{
		rotate_a(&stack_a);
		return ;
	}
	else if (argc == 4)
		sort_three(&stack_a, &stack_b);
	else if (argc >= 5 && argc <= 6)
		sort_four_five(&stack_a, &stack_b, argc);
	else if (argc < 26)
		sort_twentysix(&stack_a, &stack_b);
	zero_order(stack_a);
	order_input(stack_a);
	max_order = find_biggest_order(stack_a);
	radix_sort(&stack_a, &stack_b, max_order);
}

static int	number_of_ints(char **argv)
{
	int	count;

	count = 1;
	while (argv[count])
		count++;
	return (count);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = number_of_ints(argv);
		stack_a = create_stack(argv, argc);
		free_strings(argv, 0);
		if (argc < 2)
			free_stack(stack_a);
	}
	else
		stack_a = create_stack(argv, argc);
	sort_by_argc(stack_a, argc);
	return (0);
}
