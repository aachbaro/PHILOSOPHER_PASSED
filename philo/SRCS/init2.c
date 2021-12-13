/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:44:25 by aachbaro          #+#    #+#             */
/*   Updated: 2021/12/06 19:07:37 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_state(t_data *data)
{
	int	i;

	i = 0;
	data->state.over = 0;
	data->state.p_ate = 0;
	pthread_mutex_init(&data->state.mut_meal, NULL);
	pthread_mutex_init(&data->state.mut_over, NULL);
	data->state.last_meal = malloc(sizeof(int) * data->param.nb_philo);
	if (!data->state.last_meal)
		return (-1);
	while (i < data->param.nb_philo)
	{
		data->philo[i].state = &data->state;
		data->state.last_meal[i] = 0;
		i++;
	}
	return (0);
}
