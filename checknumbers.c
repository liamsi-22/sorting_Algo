#include "pushswap.h"

// int checknumbers(char *str)
// {
//     int i;

//     i = 0;
//     while(str[i])
//     {
//         while(str[i] == ' ')
//             i++;
//         if(str[i] == '+' || str[i] == '-')
//             {
//                 if((str[i + 1] < '0' || str[i + 1] > '9'))
//                     return (-1);
//                 else
//                     if (str[i]) 
//                         i++;
//             }
//         if((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != '+' && str[i] != '-' && str[i])
//            return (-2);
//         i++;

//     }
//     return (1);
// }

int checknumbers(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        while(str[i] == ' ')
            i++;
        if((str[i] == '+' || str[i] == '-') && (str[i + 1] < '0' || str[i + 1] > '9'))
            return (-1);
        else if ((str[i] == '+' || str[i] == '-') && !(str[i + 1] < '0' || str[i + 1] > '9'))
            i++;
        while (str[i] >= '0' && str[i] <= '9')
            i++;
        if (str[i] != ' ' && str[i] != '\0')
           return (-1);
        i++;
    }
    return (1);
}
