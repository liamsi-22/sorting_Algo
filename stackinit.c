#include "pushswap.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
t_list	*ft_lstnew(int x)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->x = x;
	new->next = NULL;
	return (new);
} 

t_list *stackinit(t_list *stack_a, char *str)
{
    int i;

    i = 0;
    char **st = ft_split(str,' ');
    while (st[i])
    {
        ft_lstadd_back(&stack_a,ft_lstnew(ft_atoi(st[i])));
        i++;
    }
    return (stack_a);
}