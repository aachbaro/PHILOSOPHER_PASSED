/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:44:25 by aachbaro          #+#    #+#             */
/*   Updated: 2021/11/17 17:11:02 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_philo(t_data *data)
{
	int		i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->param.nb_philo);
	if (!data->philo)
		return (-1);
	while (i < data->param.nb_philo)
	{
		data->philo[i].number = i;
		data->philo[i].meal = 0;
		data->philo[i].param = data->param;
		data->philo[i].speaks = &data->speaks;
		data->philo[i].start = data->start;
		i++;
	}
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->param.nb_philo);
	if (!data->forks)
		return (-1);
	while (i < data->param.nb_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (0);
}

void	link_forks_to_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->param.nb_philo - 1)
	{
		data->philo[i].right_f = &data->forks[i];
		data->philo[i].left_f = &data->forks[i + 1];
		i++;
	}
	data->philo[i].right_f = &data->forks[i];
	data->philo[i].left_f = &data->forks[0];
}

int	init_all(t_data *data)
{
	data->start = get_time();
	pthread_mutex_init(&data->speaks, NULL);
	if (init_philo(data) == -1)
		return (-1);
	if (init_forks(data) == -1)
	{
		free(data->philo);
		return (-1);
	}
	link_forks_to_philo(data);
	if (init_state(data) == -1)
	{
		free(data->philo);
		free(data->forks);
		return (-1);
	}
	return (0);
}
