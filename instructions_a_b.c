/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:34:20 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/05/12 15:57:11 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ss(t_list *a, t_list *b)
{
	int	tmp1;
	int	tmp2;

	if (a == NULL || a->next == NULL || b == NULL || b->next == NULL)
		return ;
	tmp1 = a->x;
	a->x = a->next->x;
	a->next->x = tmp1;
	tmp2 = b->x;
	b->x = b->next->x;
	b->next->x = tmp2;
	write(1, "ss\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*b == NULL || *a == NULL || (*b)->next == NULL || (*a)->next == NULL)
		return ;
	tmp1 = *b;
	ft_lstlast(*b)->next = tmp1;
	*b = (*b)->next;
	tmp1->next = NULL;
	tmp2 = *a;
	ft_lstlast(*a)->next = tmp2;
	*a = (*a)->next;
	tmp2->next = NULL;
	write(1, "rr\n", 3);
}

void	rrr(t_list **a, t_list **b)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	tmp1 = ft_lstlast(*a);
	ft_lstbfrlast(*a)->next = NULL;
	ft_lstadd_front(a, tmp1);
	tmp2 = ft_lstlast(*b);
	ft_lstbfrlast(*b)->next = NULL;
	ft_lstadd_front(b, tmp2);
	write(1, "rrr\n", 4);
}
