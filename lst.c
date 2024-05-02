#include "pushswap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstbfrlast(t_list *lst)
{
	while (lst != NULL && lst->next->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}