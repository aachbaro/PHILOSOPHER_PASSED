/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:00:30 by aachbaro          #+#    #+#             */
/*   Updated: 2021/12/01 19:08:14 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	thread_handler(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_create(&data->nar, NULL, &narator, data) != 0)
		return (-1);
	while (i < data->param.nb_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL,
				&philo, &data->philo[i]) != 0)
			return (-1);
		i++;
	}
	i = 0;
	pthread_join(data->nar, NULL);
	while (i < data->param.nb_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	return (0);
}
