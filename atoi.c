#include "pushswap.h"

long long	ft_atoi(char *str)
{
	long long	n;
	int				sign;
	int				i;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}

	return (sign * n);
}
