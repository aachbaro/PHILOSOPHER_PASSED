/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   narator_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:29:18 by aachbaro          #+#    #+#             */
/*   Updated: 2021/12/08 15:47:34 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	to_bad(int time, int nb, pthread_mutex_t *speaks)
{
	pthread_mutex_lock(speaks);
	ft_putnbr(time);
	write(1, " ", 1);
	ft_putnbr(nb);
	write(1, " died\n", 6);
	pthread_mutex_unlock(speaks);
}

int	check_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->param.nb_philo)
	{
		if (get_time() - data->start
			- data->state.last_meal[i] > data->param.die_t)
		{
			pthread_mutex_unlock(&data->state.mut_meal);
			pthread_mutex_lock(&data->state.mut_over);
			data->state.over = 1;
			pthread_mutex_unlock(&data->state.mut_over);
			to_bad(get_time() - data->start, i, &data->speaks);
			return (-1);
		}
		pthread_mutex_unlock(&data->state.mut_meal);
		pthread_mutex_lock(&data->state.mut_meal);
		i++;
	}
	return (0);
}

void	*narator(void *data)
{
	t_data	*cpy;

	cpy = (t_data *)data;
	while (1)
	{
		pthread_mutex_lock(&cpy->state.mut_meal);
		if (cpy->state.p_ate >= cpy->param.nb_philo
			&& cpy->param.simul_end != -1)
		{
			pthread_mutex_unlock(&cpy->state.mut_meal);
			pthread_mutex_lock(&cpy->state.mut_over);
			cpy->state.over = 1;
			pthread_mutex_unlock(&cpy->state.mut_over);
			return (NULL);
		}
		if (check_dead(data))
			return (NULL);
		pthread_mutex_unlock(&cpy->state.mut_meal);
	}
}
