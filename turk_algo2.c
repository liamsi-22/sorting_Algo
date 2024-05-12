/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:04:26 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/05/12 16:06:41 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_sign(int sign, t_list **target, t_list **a2)
{
	if (sign == 1)
		*target = lst_min(*a2);
}

void	push_except3(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	while (size > 3)
	{
		pb(a, b);
		size = ft_lstsize(*a);
	}
	if (check_order(*a) == -1)
		sort_3(a);
}

t_list	*find_target(int y, t_list *a)
{
	int		sign;
	t_list	*a2;
	t_list	*target;

	target = NULL;
	sign = 1;
	a2 = a;
	while (a != NULL)
	{
		if (a->x > y)
		{
			target = a;
			sign *= -1;
			break ;
		}
		a = a->next;
	}
	while (a != NULL)
	{
		if ((a->x > y) && (a->x < target->x))
			target = a;
		a = a->next;
	}
	check_sign(sign, &target, &a2);
	return (target);
}

void	fill_stacks(t_list *b, t_list *a)
{
	int		size;
	int		i;
	t_list	*tmp;

	size = ft_lstsize(b);
	i = 0;
	tmp = b;
	while (tmp)
	{
		tmp->position = i;
		tmp->target_node = find_target(tmp->x, a);
		if (i > (size / 2))
		{
			tmp->position = size - tmp->position;
			tmp->up = 0;
		}
		else
			tmp->up = 1;
		tmp = tmp->next;
		i++;
	}
	fill_positiona(a);
	fill_swap_cost(b);
}
