/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:03:55 by czhu              #+#    #+#             */
/*   Updated: 2025/02/08 16:13:09 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

/* think */
void	think(t_philo *philo)
{
	print_message(philo, "is thinking", philo->id);
}

/* sleep */
void	sleep_philo(t_philo *philo)
{
	print_message(philo, "is sleeping", philo->id);
	ft_usleep(philo->time_to_sleep);
}

/* update eating status, last_meal time, and meals_eaten count */
void	update_meal_status(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	philo->eating = 1;
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
}

/* eat
    - lock both forkss
    - update meal count & last meal time
    - simulate eating by pause the time
    - release fork after eating
    - handle the case of a single philo
*/
void	eat(t_philo *philo)
{
    pthread_mutex_lock(philo->right_fork);
    print_message(philo, "has taken a fork", philo->id);
    if (philo->num_philo == 1)
    {
        ft_usleep(philo->time_to_die);
        pthread_mutex_unlock(philo->right_fork);
        return ;
    }
    pthread_mutex_lock(philo->left_fork);
    print_message(philo, "has taken a fork", philo->id);
    update_meal_status(philo);  
    print_message(philo, "is eating", philo->id);
    ft_usleep(philo->time_to_eat); 
    pthread_mutex_lock(philo->meal_lock);
    philo->eating = 0;
    pthread_mutex_unlock(philo->meal_lock);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}
