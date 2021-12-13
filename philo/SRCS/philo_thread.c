/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:43:17 by aachbaro          #+#    #+#             */
/*   Updated: 2021/12/08 15:44:24 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo(void *philo)
{
	t_philo	*cpy;

	cpy = (t_philo *)philo;
	if (cpy->number % 2 == 0)
		ft_usleep(10);
	while (1)
	{
		if (is_over((t_philo *)philo))
			return (NULL);
		philo_eat((t_philo *)philo);
		if (is_over((t_philo *)philo))
			return (NULL);
		speaks(get_time() - cpy->start, cpy, " is sleeping\n", 13);
		ft_usleep(cpy->param.sleep_t);
		if (is_over((t_philo *)philo))
			return (NULL);
		speaks(get_time() - cpy->start, cpy, " is thinking\n", 13);
	}
	return (NULL);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_f);
	speaks(get_time() - philo->start, philo, " has taken a fork\n", 18);
	if (philo->param.nb_philo != 1)
		pthread_mutex_lock(philo->left_f);
	else
		ft_usleep(philo->param.die_t);
	speaks(get_time() - philo->start, philo, " has taken a fork\n", 18);
	speaks(get_time() - philo->start, philo, " is eating\n", 11);
	philo->meal++;
	pthread_mutex_lock(&philo->state->mut_meal);
	if (philo->meal == philo->param.simul_end)
		philo->state->p_ate++;
	philo->state->last_meal[philo->number] = get_time() - philo->start;
	pthread_mutex_unlock(&philo->state->mut_meal);
	if (!is_over(philo))
		ft_usleep(philo->param.eat_t);
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
}
