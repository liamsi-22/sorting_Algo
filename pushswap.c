/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:34:06 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/05/11 19:04:03 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int ac, char **av)
{
    int i;
    char *str;
    t_list *stack_a;
    t_list *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    str = " ";
    i = 1;
    if (ac < 2)
        return (1);
    while(av[i])
    {
        if((!av[i][0]) || checkdgts(av[i]) == -1)
        {
            if (i > 1)
                free(str);
            return (write(2, "Error\n", 6),1);
        }
        str = ft_strjoin(str,ft_strjoin(av[i]," "));
        i++;
    }
    if (checknumbers(str) == -1 || checkminmax(str) == -1 || checkdouble(str) == -1)
    {
        free(str);
        return (write(2, "Error\n", 6),1);
    }
    stack_a = stackinit(stack_a, str);
    if(check_order(stack_a) == -1)
    {
        if(ft_lstsize(stack_a) == 2)
            sa(stack_a);
        if(ft_lstsize(stack_a) == 3)
            sort_3(&stack_a);
        if(ft_lstsize(stack_a) > 3)
            turk_algo(&stack_a,&stack_b);
    }
    free(stack_a);
    //system("leaks ./push_swap");
}
