#include "push_swap.h"

//// Returns 1 if first node in stack_a contains smallest number,
///  else returns 0
int	is_smallest(t_list *stack_a)
{
	long	check;

	check = stack_a->content;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->content < check)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	count_stack_size(t_list *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

//// Checks if stack is sorted. If yes then exit.
void	is_sorted_check(t_list *stack_a)
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
		exit(0);
}

//// Finds and returns biggest order number.
int	find_biggest_order(t_list *stack_a)
{
	int	ret;

	ret = 0;
	while (stack_a)
	{
		if (ret < stack_a->order)
			ret = stack_a->order;
		stack_a = stack_a->next;
	}
	return (ret);
}
