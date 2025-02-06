#include "../incl/philo.h"

/* think */
void    think(t_philo *philo)
{
    print_message(philo, "is thinking", philo->id);
}

/* sleep */
void    sleep_philo(t_philo *philo)
{
    print_message(philo, "is sleeping", philo->id);
}

/* eat
    - lock both forkss
    - update meal count & last meal time
    - simulate eating by pause the time
    - release fork after eating
    - handle the case of a single philo

*/
void    eat(t_philo *philo)
{
    // lock the right fork
    pthread_mutex_lock(philo->right_fork);
    print_message(philo, "has taken a fork", philo->id);
    // handle the case of a single philo
    if (philo->num_philo == 1)
    {
        ft_usleep(philo->time_to_die);
        pthread_mutex_unlock(philo->right_fork);
        return ;
    }
    // lock the left fork
    pthread_mutex_lock(philo->left_fork);
    print_message(philo, "has taken a fork", philo->id);
    // update eating
    philo->eating = 1;
    print_message(philo, "has taken a fork", philo->id);
    // update last meal, meal eaten
    pthread_mutex_lock(philo->meal_lock);
    philo->last_meal = get_current_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(philo->meal_lock);
    ft_usleep(philo->time_to_eat);
    // reset eating
    philo->eating = 0;
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}