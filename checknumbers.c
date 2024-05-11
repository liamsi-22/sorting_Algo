/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checknumbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:34:22 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/05/11 18:34:23 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int checkdgts(char *str)
{
    int i;

    i = 0;
    while (str[i]  == ' ')
        i++;
    if(str[i] == '\0')
        return -1;
    return 1;
}

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
    }
    return (1);
}
