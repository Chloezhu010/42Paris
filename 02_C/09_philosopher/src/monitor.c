/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:59:18 by czhu              #+#    #+#             */
/*   Updated: 2025/02/08 16:20:01 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

/*
    check if a philo is dead
    - if the philo has starvation
    - return 1 if starved, return 0 if not
*/
int	philo_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (philo->eating == 0
		&& get_current_time() - philo->last_meal >= time_to_die)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

/*
    check if any philo is dead
    - return 1 if someone died, return 0 if not
*/
int	check_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].num_philo)
	{
		if (philo_dead(&philo[i], philo[i].time_to_die))
		{
			print_message(&philo[i], "died", philo[i].id);
			pthread_mutex_lock(philo[0].dead_lock);
			*philo->dead = 1;
			pthread_mutex_unlock(philo[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

/*
    check if all the philos have eaten the num of meals
    - if all have eaten
        - set dead flag as 1 to complete the process
        - return 1
    - if not all have eatn or no arg
        - return 0
*/
int	check_all_eat(t_philo *philo)
{
	int	i;
	int	finish_eating;

	i = 0;
	finish_eating = 0;
	if (philo[0].num_times_to_eat == -1)
		return (0);
	while (i < philo[0].num_philo)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meals_eaten > philo[i].num_times_to_eat)
			finish_eating++;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (finish_eating == philo[0].num_philo)
	{
		pthread_mutex_lock(philo[0].dead_lock);
		*philo->dead = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		return (1);
	}
	return (0);
}

/*
    monitor thread routine
    - if there is phio dead or all have eaten, terminate the process
*/
void	*monitor(void *arg)
{	
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (check_dead(philo) == 1 || check_all_eat(philo) == 1)
			break ;
	}
	return (NULL);
}
