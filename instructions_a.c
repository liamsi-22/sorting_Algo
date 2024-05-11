/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:34:17 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/05/11 18:34:18 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void sa(t_list *stack_a)
{
    int tmp;

    if(stack_a == NULL || stack_a->next == NULL)
        return ;
    tmp = stack_a->x;
    stack_a->x = stack_a->next->x;
    stack_a->next->x = tmp;
    write(1, "sa\n", 3);
}

void ra(t_list **stack_a)
{
    t_list *tmp1;

    if(*stack_a == NULL || (*stack_a)->next == NULL)
        return ;
    tmp1 = *stack_a;
    ft_lstlast(*stack_a)->next = tmp1;
    *stack_a = (*stack_a)->next;
    tmp1->next = NULL;
    write(1, "ra\n", 3);
}
void rra(t_list **stack_a)
{
    t_list *last;

    if(*stack_a == NULL || (*stack_a)->next == NULL)
        return ;
    last = ft_lstlast(*stack_a);
    ft_lstbfrlast(*stack_a)->next = NULL;
    ft_lstadd_front(stack_a, last);
    write(1, "rra\n", 4);
}

void pb(t_list **a, t_list **b)
{
    t_list *tmp;

    if(*a == NULL)
        return ;
    tmp = *a;
    *a = tmp->next;
    ft_lstadd_front(b, tmp);
    write(1, "pb\n", 3);
}
