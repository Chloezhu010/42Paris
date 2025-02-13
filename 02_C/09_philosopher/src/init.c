/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:48:42 by czhu              #+#    #+#             */
/*   Updated: 2025/02/08 16:17:30 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

/* init the input from user */
void	init_input(t_philo *philo, char **av)
{
	philo->num_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->num_times_to_eat = ft_atoi(av[5]);
	else
		philo->num_times_to_eat = -1;
}

/* init philo */
void	init_philo(t_philo *philo, t_program *program,
		pthread_mutex_t *fork, char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philo[i].id = i + 1;
		philo[i].eating = 0;
		philo[i].meals_eaten = 0;
		init_input(&philo[i], av);
		philo[i].last_meal = program->start_time;
		philo[i].start_time = program->start_time;
		philo[i].dead = &program->dead_flag;
		philo[i].write_lock = &program->write_lock;
		philo[i].dead_lock = &program->dead_lock;
		philo[i].meal_lock = &program->meal_lock;
		philo[i].left_fork = &fork[i];
		if (i == philo[i].num_philo - 1)
			philo[i].right_fork = &fork[0];
		else
			philo[i].right_fork = &fork[i + 1];
		i++;
	}
}

/* init fork mutex */
void	init_fork(pthread_mutex_t *fork, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
}

/* init program structure */
void	init_program(t_program *program, t_philo *philo)
{
	program->dead_flag = 0;
	program->philo = philo;
	program->start_time = get_current_time();
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}
