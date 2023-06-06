#include "push_swap.h"

void	error_check(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp;
	long	check;
	t_list	*free;

	if (!stack_a && !stack_b)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	free = stack_a;
	while (stack_a)
	{
		if ((stack_a->content > 2147483647) | (stack_a->content < -2147483648))
			free_stack(free);
		temp = stack_a->next;
		check = stack_a->content;
		while (temp)
		{
			if (check == temp->content)
				free_stack(free);
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
}

void	free_strings(char **ret_arr, int error)
{
	int	i;

	i = 1;
	while (ret_arr[i])
	{
		free(ret_arr[i]);
		i++;
	}
	free(ret_arr);
	if (error)
		error_check(NULL, NULL);
}

void	free_stack(t_list *stack_a)
{
	t_list	*temp;

	while (stack_a)
	{
		temp = stack_a;
		free(stack_a);
		stack_a = temp->next;
	}
	error_check(NULL, NULL);
}
