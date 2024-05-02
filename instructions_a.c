#include "pushswap.h"

void sa(t_list *stack_a)
{
    int tmp;

    if(stack_a == NULL || stack_a->next == NULL)
        return ;
    tmp = stack_a->x;
    stack_a->x = stack_a->next->x;
    stack_a->next->x = tmp;
}

void ra(t_list **stack_a)
{
    t_list *tmp1;

    if(stack_a == NULL || (*stack_a)->next == NULL)
        return ;
    tmp1 = *stack_a;
    ft_lstlast(*stack_a)->next = tmp1;
    *stack_a = (*stack_a)->next;
    tmp1->next = NULL;
}
void rra(t_list **stack_a)
{
    t_list *last;

    if(stack_a == NULL || (*stack_a)->next == NULL)
        return ;
    last = ft_lstlast(*stack_a);
    ft_lstbfrlast(*stack_a)->next = NULL;
    ft_lstadd_front(stack_a, last);
}

void pb(t_list **a, t_list **b)
{
    t_list *tmp;

    if(a == NULL)
        return ;
    tmp = *a;
    *a = tmp->next;
    ft_lstadd_front(b,tmp);
}

