/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:13:16 by czhu              #+#    #+#             */
/*   Updated: 2025/02/08 16:22:07 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

/*
    check if the value of dead_flag changed
    - return 1 if dead, return 0 if alive
    - used to determine the philo_routine activity
   	 prevent further action if he died
*/
int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

/*
    create thread routine for each philo 
    - even number philo wait 1ms to start, avoiding fork deadlock
*/
void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead_loop(philo))
	{
		eat(philo);
		sleep_philo(philo);
		think(philo);
	}
	return (NULL);
}

/* create & join all threads
    - create a observer thread to monitor the state of the phio
    - create thread for each phio, executing daily routine
    - join observer thread
    - join thread of each phio
    - if anything fails, destory all
*/
int	create_thread(t_program *program, pthread_mutex_t *fork)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitor, program->philo) != 0)
		destory_all(program, fork);
	i = 0;
	while (i < program->philo[0].num_philo)
	{
		if (pthread_create(&program->philo[i].thread, NULL,
				&philo_routine, &program->philo[i]) != 0)
			destory_all(program, fork);
		i++;
	}
	if (pthread_join(observer, NULL) != 0)
		destory_all(program, fork);
	i = 0;
	while (i < program->philo[0].num_philo)
	{
		if (pthread_join(program->philo[i].thread, NULL) != 0)
			destory_all(program, fork);
		i++;
	}
	return (0);
}

/* print message */
void	print_message(t_philo *philo, char *str, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}
