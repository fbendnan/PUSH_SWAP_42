#include "push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstdelone(t_stack *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	(*del)(lst->value);
	(*del)(lst->index);
	free (lst);
}
