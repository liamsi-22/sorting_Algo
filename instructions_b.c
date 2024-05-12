/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:34:15 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/05/12 15:57:18 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sb(t_list *stack_b)
{
	int	tmp1;

	if (stack_b == NULL || stack_b->next == NULL)
		return ;
	tmp1 = stack_b->x;
	stack_b->x = stack_b->next->x;
	stack_b->next->x = tmp1;
	write(1, "sb\n", 3);
}

void	rb(t_list **stack_b)
{
	t_list	*tmp1;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp1 = *stack_b;
	ft_lstlast(*stack_b)->next = tmp1;
	*stack_b = (*stack_b)->next;
	tmp1->next = NULL;
	write(1, "rb\n", 3);
}

void	rrb(t_list **stack_b)
{
	t_list	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = ft_lstlast(*stack_b);
	ft_lstbfrlast(*stack_b)->next = NULL;
	ft_lstadd_front(stack_b, last);
	write(1, "rrb\n", 4);
}

void	pa(t_list **b, t_list **a)
{
	t_list	*tmp1;

	if (*b == NULL)
		return ;
	tmp1 = *b;
	*b = tmp1->next;
	ft_lstadd_front(a, tmp1);
	write(1, "pa\n", 3);
}
