/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:34:30 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/05/12 15:56:56 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_arrayy(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	checkminmax(char *str)
{
	int		i;
	char	**st;

	i = 0;
	st = ft_split(str, ' ');
	while (st[i])
	{
		if (ft_atoi(st[i]) > INTMAX || ft_atoi(st[i]) < INTMIN)
			return (free_arrayy(st), -1);
		i++;
	}
	free_arrayy(st);
	return (1);
}
