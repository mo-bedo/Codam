#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
		(*lst)->prev = new;
	new->next = *lst;
	new->prev = NULL;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = ft_lstlast(*lst);
	if (temp == 0)
		*lst = new;
	else
	{
		temp->next = new;
		new->prev = temp;
	}
	new->next = NULL;
}

t_list	*ft_lstnew(long content)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (new == 0)
		return (0);
	new->content = content;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
