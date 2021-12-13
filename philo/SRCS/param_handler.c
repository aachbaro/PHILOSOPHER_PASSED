/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:13:14 by aachbaro          #+#    #+#             */
/*   Updated: 2021/11/10 14:57:24 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	param_handler(t_param *param, int ac, char **av)
{	
	if (ac < 5 || ac > 6)
		return (-1);
	if (check_param(ac, av) == -1)
		return (-1);
	param->nb_philo = ft_atoi(av[1]);
	param->die_t = ft_atoi(av[2]);
	param->eat_t = ft_atoi(av[3]);
	param->sleep_t = ft_atoi(av[4]);
	if (ac == 6)
		param->simul_end = ft_atoi(av[5]);
	else
		param->simul_end = -1;
	return (0);
}

int	check_digit(char *str)
{
	char	*tmp;
	char	**tab;
	int		i;

	tab = ft_split(str, ' ');
	if (!tab)
		return (-1);
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	if (i != 1)
		return (-1);
	tmp = ft_itoa(ft_atoi(str));
	if (!tmp)
		return (-1);
	if (ft_strncmp(str, tmp, ft_strlen(str)))
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (0);
}

int	check_param(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (check_digit(av[i]) == -1)
			return (-1);
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) || av[i][j] == ' ')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
