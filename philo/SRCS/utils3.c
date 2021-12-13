/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:40:26 by aachbaro          #+#    #+#             */
/*   Updated: 2021/11/15 12:42:26 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	cpy;

	cpy = nb;
	if (cpy < 0)
	{
		write(1, "-", 1);
		cpy = -cpy;
	}
	if (cpy > 9)
		ft_putnbr(cpy / 10);
	ft_putchar(cpy % 10 + '0');
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

long int	get_time(void)
{
	struct timeval	time;
	int				ret;

	gettimeofday(&time, NULL);
	ret = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ret);
}

void	ft_usleep(long int usec)
{
	long int	start;

	start = get_time();
	while (get_time() - start < usec)
		usleep(usec / 10);
}
