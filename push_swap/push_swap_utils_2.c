#include "push_swap.h"

static long	ft_atoi(const char *str, t_list *stack)
{
	int		i;
	int		minus;
	long	ret;

	i = 0;
	minus = 0;
	if (str[i] == '-' || str[i] == '+')
		minus = str[i++];
	if (str[i] < '0' || str[i] > '9' || !str[i])
		free_stack(stack);
	ret = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret *= 10;
		ret += (str[i] - 48);
		i++;
	}
	if ((str[i] < '0' || str[i] > '9') && str[i])
		free_stack(stack);
	if (minus == 45)
		return (-(ret));
	return (ret);
}

//// Creates the stack from argv. Also checks for integer limits.
t_list	*create_stack(char *argv[], int argc)
{
	t_list	*temp;
	t_list	*ret_list;
	int		i;

	i = 1;
	ret_list = 0;
	while (i < argc)
	{
		temp = ft_lstnew(ft_atoi(argv[i], ret_list));
		if (!temp)
			free_stack(ret_list);
		ft_lstadd_back(&ret_list, temp);
		i++;
	}
	return (ret_list);
}
