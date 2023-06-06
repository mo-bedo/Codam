#include "push_swap.h"

////    Take first element of top of b and put it at top of a.
//// 	Do nothing if b is empty.
void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	temp;

	if (!(*stack_b))
		return ;
	else if (count_stack_size(*stack_b) < 2)
	{
		ft_lstadd_front(stack_a, *stack_b);
		*stack_b = NULL;
	}
	else
	{
		temp = **stack_b;
		ft_lstadd_front(stack_a, *stack_b);
		*stack_b = temp.next;
		(*stack_b)->prev = NULL;
	}
	write(1, "pa\n", 3);
}

////    Take first element of top of a and put in at top of b.
//// 	Do nothing if b is empty.
void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	temp;

	if (!(*stack_a))
		return ;
	else if (count_stack_size(*stack_a) < 2)
	{
		ft_lstadd_front(stack_b, *stack_a);
		*stack_a = NULL;
	}
	else
	{
		temp = **stack_a;
		ft_lstadd_front(stack_b, *stack_a);
		*stack_a = temp.next;
		(*stack_a)->prev = NULL;
	}
	write(1, "pb\n", 3);
}

////    Shifts up all elements of stack a by 1.
//// 	First element becomes last element.
void	rotate_a(t_list **stack_a)
{
	t_list	*temp;

	if (!*stack_a || count_stack_size(*stack_a) == 1)
		return ;
	(*stack_a)->next->prev = NULL;
	temp = (*stack_a)->next;
	ft_lstadd_back(stack_a, *stack_a);
	*stack_a = temp;
	write(1, "ra\n", 3);
}

void	reverse_rotate_a(t_list **stack_a)
{
	t_list	*temp;

	if (!*stack_a || count_stack_size(*stack_a) == 1)
		return ;
	temp = ft_lstlast(*stack_a);
	temp->prev->next = NULL;
	ft_lstadd_front(stack_a, temp);
	write(1, "rra\n", 4);
}

////    Swap the first 2 elements at the top of stack a.
////	Do nothing if there are < 2 elements.
void	swap_a(t_list **stack_a)
{
	t_list	*temp;

	if (count_stack_size(*stack_a) < 2)
		return ;
	else if (count_stack_size(*stack_a) == 2)
	{
		ft_lstadd_front(stack_a, (*stack_a)->next);
		(*stack_a)->next->next = NULL;
		write(1, "sa\n", 3);
		return ;
	}
	else
	{
		temp = (*stack_a)->next->next;
		ft_lstadd_front(stack_a, (*stack_a)->next);
		temp->prev = (*stack_a)->next;
		(*stack_a)->next->next = temp;
		write(1, "sa\n", 3);
		return ;
	}
}
