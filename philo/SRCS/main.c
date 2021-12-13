/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:30:46 by aachbaro          #+#    #+#             */
/*   Updated: 2021/12/01 19:07:10 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (param_handler(&data.param, ac, av) == -1)
	{
		printf("Error\n");
		return (-1);
	}
	if (data.param.nb_philo)
	{
		if (init_all(&data) == -1)
			return (-1);
		if (data.param.simul_end)
		{
			if (thread_handler(&data) == -1)
				printf("Erreur lors de pthread_create\n");
		}
		free_all(&data);
	}
	return (0);
}
