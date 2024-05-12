/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:34:26 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/05/12 15:57:03 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	checkdouble(char *str)
{
	int		i;
	int		j;
	int		tmp;
	char	**st;

	i = 0;
	j = 0;
	st = ft_split(str, ' ');
	while (st[i])
	{
		j = i + 1;
		tmp = atoi(st[i]);
		while (st[j])
		{
			if (tmp == atoi(st[j]))
				return (free_arrayy(st), -1);
			j++;
		}
		i++;
	}
	free_arrayy(st);
	return (1);
}
