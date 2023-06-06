#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	long			content;
	int				order;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

////	sort_three.c
void	sort_three(t_list **stack_a, t_list **stack_b);
void	sort_four_five(t_list **stack_a, t_list **stack_b, int argc);

////	doubly_linked_list.c
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(long content);
t_list	*ft_lstlast(t_list *lst);

////	ft_split.c
char	**ft_split(char const *s, char c);

////	sorter_functions.c
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	swap_a(t_list **stack_a);
void	reverse_rotate_a(t_list **stack_a);

////	push_swap_utils.c
int		count_stack_size(t_list *stack);
void	is_sorted_check(t_list *stack_a);
int		find_biggest_order(t_list *stack_a);
int		is_smallest(t_list *stack_a);

////	push_swap_utils_2.c
t_list	*create_stack(char **argv, int argc);

////	radix.c
void	zero_order(t_list *stack_a);
void	order_input(t_list *stack_a);
void	radix_sort(t_list **stack_a, t_list **stack_b, int max_order);

////	errorcheck.c
void	free_stack(t_list *stack_a);
void	free_strings(char **ret_arr, int error);
void	error_check(t_list *stack_a, t_list *stack_b);

#endif
