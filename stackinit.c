/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:34:00 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/05/11 19:01:21 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
int	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return (0);
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
	return (1);
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

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = *lst;
			*lst = (*lst)->next;
			free(tmp);
		}
	}
}
t_list *stackinit(t_list *stack_a, char *str)
{
    int i;

    i = 0;
    char **st = ft_split(str,' ');
    while (st[i])
    {
        if (ft_lstadd_back(&stack_a,ft_lstnew(ft_atoi(st[i]))) == 0)
			ft_lstclear(&stack_a);
        i++;
    }
	free(str);
    return (stack_a);
}
