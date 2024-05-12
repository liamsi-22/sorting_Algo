/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:34:28 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/05/12 15:56:58 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_order(t_list *stack)
{
	while (stack && stack->next != NULL)
	{
		if (stack->x > stack->next->x)
			return (-1);
		stack = stack->next;
	}
	return (1);
}

t_list	*lst_min(t_list *lst)
{
	t_list	*min;

	min = lst;
	while (lst->next != NULL)
	{
		if (min->x > lst->next->x)
			min = lst->next;
		lst = lst->next;
	}
	return (min);
}

int	lst_max(t_list *lst)
{
	int	max;

	max = lst->x;
	while (lst->next != NULL)
	{
		if (max < lst->next->x)
			max = lst->next->x;
		lst = lst->next;
	}
	return (max);
}

void	sort_3(t_list **lst)
{
	int	max;

	max = lst_max(*lst);
	if (max == ft_lstlast(*lst)->x)
		sa(*lst);
	else
	{
		if (max == (*lst)->x)
			ra(lst);
		else
			rra(lst);
		if (check_order(*lst) == -1)
			sa(*lst);
	}
}
