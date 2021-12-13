/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:18:41 by aachbaro          #+#    #+#             */
/*   Updated: 2021/12/08 15:48:05 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_param
{
	int	nb_philo;
	int	die_t;
	int	eat_t;
	int	sleep_t;
	int	simul_end;
}		t_param;

typedef struct s_state
{
	pthread_mutex_t	mut_meal;
	pthread_mutex_t	mut_over;
	int				over;
	int				p_ate;
	int				*last_meal;
}					t_state;

typedef struct s_philo
{
	int				number;
	int				meal;
	pthread_t		thread;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	t_param			param;
	pthread_mutex_t	*speaks;
	int				start;
	t_state			*state;
}					t_philo;

typedef struct s_data
{
	t_param			param;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_t		nar;
	pthread_mutex_t	speaks;
	t_state			state;
	int				start;
}					t_data;

int			ft_atoi(const char *str);
char		*ft_itoa(int n);
int			ft_isdigit(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *str);
char		**ft_split(const char *str, char c);
int			param_handler(t_param *param, int ac, char **av);
int			check_digit(char *str);
int			check_param(int ac, char **av);
int			init_philo(t_data *data);
int			init_forks(t_data *data);
void		link_forks_to_philo(t_data *data);
int			init_state(t_data *data);
int			init_all(t_data *data);
void		free_all(t_data *data);
long int	get_time(void);
void		ft_usleep(long int usec);
void		ft_putchar(char c);
void		ft_putnbr(int nb);
void		ft_putstr(char *s);
void		speaks(int time, t_philo *philo, char *str, int len);
void		*philo(void *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
void		philo_eat(t_philo *philo);
int			check_end(t_philo *philo);
int			thread_handler(t_data *data);
void		*narator(void *data);
int			is_over(t_philo *philo);

#endif
