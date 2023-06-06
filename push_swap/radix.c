#include "push_swap.h"

void	radix_sort(t_list **stack_a, t_list **stack_b, int order_max)
{
	int		bits;
	int		i;
	int		nodes;
	int		nodes_b;

	bits = 0;
	while (order_max >> bits)
		bits++;
	i = 0;
	while (i < bits)
	{
		nodes = count_stack_size(*stack_a);
		while (nodes > 0)
		{
			if (((*stack_a)->order >> i) & 1)
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
			nodes--;
		}
		nodes_b = count_stack_size(*stack_b);
		while (nodes_b--)
			push_a(stack_a, stack_b);
		i++;
	}
}

void	zero_order(t_list *stack_a)
{
	while (stack_a)
	{
		stack_a->order = 0;
		stack_a = stack_a->next;
	}
}

void	order_input(t_list *stack_a)
{
	t_list	*temp;
	t_list	*small;
	long	check;
	int		nodes;

	nodes = count_stack_size(stack_a);
	temp = stack_a;
	while (nodes--)
	{
		check = -2147483649;
		stack_a = temp;
		while (stack_a)
		{
			if (!stack_a->order && check < stack_a->content)
			{
				check = stack_a->content;
				small = stack_a;
			}
			stack_a = stack_a->next;
		}
		small->order = nodes;
	}
}
