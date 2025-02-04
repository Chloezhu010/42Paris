#include "../incl/philo.h"

/*
    - lock both left and right forks
    - print that the philo has taken the fork
*/
void    pick_fork(t_philosopher *philo)
{
    pthread_mutex_lock(philo->left_fork);
    log_message(philo, "has taken a fork");
    pthread_mutex_lock(philo->right_fork);
    log_message(philo, "has taken a fork");
}

/*
    - unlock both forks
*/
void    drop_fork(t_philosopher *philo)
{
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}