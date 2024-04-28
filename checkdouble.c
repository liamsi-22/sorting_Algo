#include "pushswap.h"

int checkdouble(char *str)
{
    int i = 0;
    int j = 0;
    int tmp;
    char **st = ft_split(str,' ');
    
    while (st[i])
    {
        j = i + 1;
        tmp = atoi(st[i]);
        while (st[j])
        {
            if (tmp == atoi(st[j]))
                return (free_arrayy(st),-1);
            j++;
        }
        i++;
    }
    free_arrayy(st);
    return (1);
}