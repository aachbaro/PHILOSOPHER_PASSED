/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speaks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:07:21 by aachbaro          #+#    #+#             */
/*   Updated: 2021/12/08 15:32:16 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	speaks(int time, t_philo *philo, char *str, int len)
{
	pthread_mutex_lock(philo->speaks);
	if (is_over(philo))
	{
		pthread_mutex_unlock(philo->speaks);
		return ;
	}
	ft_putnbr(time);
	write(1, " ", 1);
	ft_putnbr(philo->number);
	write(1, str, len);
	pthread_mutex_unlock(philo->speaks);
}

void	free_all(t_data *data)
{
	free(data->forks);
	free(data->philo);
	free(data->state.last_meal);
}

int	is_over(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->mut_over);
	if (philo->state->over)
	{
		pthread_mutex_unlock(&philo->state->mut_over);
		return (1);
	}
	pthread_mutex_unlock(&philo->state->mut_over);
	return (0);
}
