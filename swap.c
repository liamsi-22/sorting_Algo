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

    tmp1 = *stack_a;
    ft_lstlast(*stack_a)->next = tmp1;
    *stack_a = (*stack_a)->next;
    tmp1->next = NULL;
}