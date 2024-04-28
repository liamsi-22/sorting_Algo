#include "pushswap.h"


int main(int ac, char **av)
{
    int i;
    char *str;
    t_list *stack_a;

    stack_a = NULL;
    str = " ";
    i = 1;
    if (ac < 2)
        return (1);
        // return (write(2, "Error\n", 6),1);
    while(av[i])
    {
        str = ft_strjoin(str,ft_strjoin(av[i]," "));
        i++;
    }
    if (checknumbers(str) == -1 || checkminmax(str) == -1 || checkdouble(str) == -1)
    {
        free(str);
        return (write(2, "Error\n", 6),1);
    }
        sa(stack_a);
    while(stack_a)
    {
        printf("%d\n",stack_a->x);
        stack_a = stack_a->next;
    }
    stack_a = stackinit(stack_a,str);
    sa(stack_a);
    ra(&stack_a);
    while(stack_a)
    {
        printf("%d\n",stack_a->x);
        stack_a = stack_a->next;
    }
}
