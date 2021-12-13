/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:36:59 by aachbaro          #+#    #+#             */
/*   Updated: 2021/11/15 12:37:44 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	nbr;

	i = 0;
	neg = 1;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			neg = -1;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * neg);
}

long	power(int pow)
{
	long	i;
	long	res;

	i = 0;
	res = 1;
	while (i < pow)
	{
		res = res * 10;
		i++;
	}
	return (res);
}

long	numsize(long n, long i)
{
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	i;
	int		j;
	long	cpy;
	int		neg;

	j = 0;
	neg = 0;
	cpy = n;
	if (cpy < 0)
	{
		neg = 1;
		cpy = -cpy;
	}
	i = numsize(cpy, 1);
	str = malloc(sizeof(char) * (i + neg + 1));
	if (!str)
		return (NULL);
	if (neg == 1)
		str[j++] = '-';
	while (i > 0)
		str[j++] = ((cpy / power(i-- - 1)) % 10) + '0';
	str[j] = 0;
	return (str);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
