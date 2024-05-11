/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:33:52 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/05/11 18:33:53 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void push_except3(t_list **a, t_list **b)
{
    int size = ft_lstsize(*a);
    while(size > 3)
    {
        pb(a, b);
        size = ft_lstsize(*a);
    }
    if(check_order(*a) == -1)
        sort_3(a);
}

t_list *find_target(int y, t_list *a)
{
    int sign;
    t_list *a2;
    t_list *target;

    target = NULL;
    sign = 1;
    a2 = a;
    while(a != NULL)
    {
        if(a->x > y)
        {
            target = a;
            sign *= -1;
            break;
        }
        a = a->next;
    }
    while (a != NULL)
    {
        if(a->x > y)
            if(a->x < target->x)
                target = a;
        a = a->next;
    }
    if(sign == 1)
        target = lst_min(a2);
    return (target);
}
void fill_stacks(t_list *b, t_list *a)
{
    int size = ft_lstsize(b);
    int i = 0;
    t_list *tmp = b;
    while (tmp)
    {
       tmp->position = i;
        tmp->target_node = find_target(tmp->x,a);
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

void    fill_swap_cost(t_list *b)
{
    while(b)
    {
        (b)->push_cost = (b)->position + (b)->target_node->position;
        (b) = (b)->next;
    }
}

void fill_positiona(t_list *a)
{
    int size = ft_lstsize(a);
    int i = 0;
    while (a)
    {
        a->position = i;
        if (i > (size / 2))
        {
            a->position = size - a->position;
            a->up = 0;
        }
        else
            a->up = 1;
        a = a->next;
        i++;
    }
}
t_list *find_cheapest(t_list *b)
{
    t_list *tmp;

    tmp = NULL;
    if (b)
    {
        tmp = b;
        while(b->next)
        {
            if (tmp->push_cost > b->next->push_cost)
                tmp = b->next;
            b = b->next;
        }
    }
    return (tmp);
}

void push_to_a(t_list **a, t_list **b)
{
    t_list *tmp = find_cheapest(*b);
    while(tmp->up == 1 && tmp->target_node->up == 1 && *b != tmp && *a != tmp->target_node)
        rr(a, b);
    while(tmp->up == 0 && tmp->target_node->up == 0 && *b != tmp && *a != tmp->target_node)
        rrr(a, b);
    while(tmp->up == 1 && *b != tmp)
        rb(b);
    while(tmp->up == 0 && *b != tmp)
        rrb(b);

    while(tmp->target_node->up == 0 && *a != tmp->target_node)
        rra(a);
    while(tmp->target_node->up == 1 && *a != tmp->target_node)
        ra(a);
    pa(b,a);
}

void turk_algo(t_list **a, t_list **b)
{
    push_except3(a, b);
    int size = ft_lstsize(*b);
    while(size > 0)
    {
        fill_stacks(*b, *a);
        push_to_a(a, b);
        size = ft_lstsize(*b);
    }
    fill_stacks(*b, *a);
    while(check_order(*a) == -1 && lst_min(*a)->up == 1)
        ra(a);
    while(check_order(*a) == -1 && lst_min(*a)->up == 0)
        rra(a);
}
