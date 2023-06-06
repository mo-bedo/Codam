#include "push_swap.h"

static int	is_biggest(t_list *stack_a)
{
	long	check;

	check = stack_a->content;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->content > check)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

static int	is_smallest_reverse(t_list *stack_a)
{
	long	check;

	check = stack_a->content;
	stack_a = stack_a->prev;
	while (stack_a)
	{
		if (stack_a->content < check)
			return (0);
		stack_a = stack_a->prev;
	}
	return (1);
}

////	Returns 1 if stack is sorted.
static int	sort_check(t_list *stack_a)
{
	size_t	count;
	size_t	i;

	i = 1;
	count = count_stack_size(stack_a);
	while (stack_a->next && (stack_a->content < stack_a->next->content))
	{
		stack_a = stack_a->next;
		i++;
	}
	if (count == i)
		return (1);
	return (0);
}

//// 	Sorts stack of three. Base on these (1 3 2)(2 3 1)(2 1 3)(3 2 1)(3 1 2)
////	possibilities. If stack b holds any ints it pushes them back in a.
void	sort_three(t_list **stack_a, t_list **stack_b)
{
	if (is_smallest(*stack_a))
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (!is_smallest(*stack_a) && !is_biggest(*stack_a))
	{
		if (is_smallest((*stack_a)->next))
			swap_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
	else
	{
		rotate_a(stack_a);
		if (!is_smallest(*stack_a))
			swap_a(stack_a);
	}
	while (*stack_b)
		push_a(stack_a, stack_b);
	exit(0);
}

////	Sorts stacks of 4 and 5. Rotates and checks if stacks are sorted.
//// 	If not uses recursion to put 2 smallest in stack b
////	and then call sort_three.
void	sort_four_five(t_list **stack_a, t_list **stack_b, int argc)
{
	if (argc >= 5)
	{
		if ((argc == 6) && is_smallest_reverse(ft_lstlast(*stack_a)))
			reverse_rotate_a(stack_a);
		while (!is_smallest(*stack_a))
		{
			rotate_a(stack_a);
			if (!*stack_b)
				is_sorted_check(*stack_a);
		}
		push_b(stack_a, stack_b);
		if (sort_check(*stack_a))
		{
			while (*stack_b)
				push_a(stack_a, stack_b);
			exit(0);
		}
		sort_four_five(stack_a, stack_b, argc - 1);
	}
	else
		sort_three(stack_a, stack_b);
}
