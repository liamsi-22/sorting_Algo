/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:34:20 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/05/11 18:34:21 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void ss(t_list *a,t_list *b)
{
    int tmp;
    int p;

    if(a == NULL || a->next == NULL)
        return ;
    tmp = a->x;
    a->x = a->next->x;
    a->next->x = tmp;


    if(b == NULL || b->next == NULL)
        return ;
    p = b->x;
    b->x = b->next->x;
    b->next->x = p;
    write(1, "ss\n", 3);
}

void rr(t_list **a,t_list **b)
{
    if(*b == NULL || *a == NULL)
        return;

    t_list *tmp1;
    t_list *o;

    if(*b == NULL || (*b)->next == NULL)
        return ;
    tmp1 = *b;
    ft_lstlast(*b)->next = tmp1;
    *b = (*b)->next;
    tmp1->next = NULL;



    if(*a == NULL || (*a)->next == NULL)
        return ;
    o = *a;
    ft_lstlast(*a)->next = o;
    *a = (*a)->next;
    o->next = NULL;
    write(1, "rr\n", 3);
}
void rrr(t_list **a,t_list **b)
{

    t_list *last;
    t_list *l;

    if(*a == NULL || (*a)->next == NULL)
        return ;
    last = ft_lstlast(*a);
    ft_lstbfrlast(*a)->next = NULL;
    ft_lstadd_front(a, last);



    if(*b == NULL || (*b)->next == NULL)
        return ;
    l = ft_lstlast(*b);
    ft_lstbfrlast(*b)->next = NULL;
    ft_lstadd_front(b, l);
    write(1, "rrr\n", 4);
}
